#include <cmath>

#include "learning_ss.h"
#include "subtraction_manager.h"
#include "eval.h"
#include "mathutils/math_util.h"

LearningSS::LearningSS(SubtractionManager& configuration):
	Subtraction(configuration),
	learning(4, std::vector<int>(2)) // Taille du vecteur : nb de paramètres ? échelle de paramètres ? alpha : 1 -> 50, beta : 0.01 -> 0.9
{
	learning.reset();
}

LearningSS::~LearningSS()
{

}

void LearningSS::operator()(std::complex<double> *input_spectrum, double* noise_spectrum)
{
	learning.startLearn();
	for (auto i = 0U; i < conf.spectrumSize(); ++i)
	{
		double Apower, Bpower, magnitude, phase, power;

		power = std::norm(input_spectrum[i]);
		phase = std::arg(input_spectrum[i]);

		Apower = power - _alpha * noise_spectrum[i];
		Bpower = _beta * power;

		magnitude = std::sqrt(std::max(Apower, Bpower));

		input_spectrum[i] = {magnitude * std::cos(phase), magnitude * std::sin(phase)};
	}
	learning.setReward(computeReward());
	learning.nextStep();
}

void LearningSS::onFFTSizeUpdate()
{

}

void LearningSS::onDataUpdate()
{

}

double LearningSS::alpha() const
{
	return _alpha;
}

void LearningSS::setAlpha(double value)
{
	_alpha = std::max(value, 0.000001);
}

double LearningSS::beta() const
{
	return _beta;
}

void LearningSS::setBeta(double value)
{
	_beta = std::max(value, 0.000001);
}

// must be called only at the end of a frame
double LearningSS::computeReward()
{
	double nrr = Eval::NRR(conf.getNoisyData(), conf.getData(), conf.getLength());
	double ret = nrr - _previousNRR;
	_previousNRR = nrr;
	return ret;
//	double sdr = Eval::SDR(origData, s_mgr.getData(), s_mgr.getLength());
}
