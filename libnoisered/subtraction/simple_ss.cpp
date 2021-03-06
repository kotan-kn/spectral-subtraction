#include <cmath>

#include "simple_ss.h"
#include "mathutils/math_util.h"
#include "subtraction_manager.h"

SimpleSpectralSubtraction::SimpleSpectralSubtraction(const SubtractionManager& configuration):
	Subtraction(configuration)
{
}

SimpleSpectralSubtraction::~SimpleSpectralSubtraction()
{

}

Subtraction *SimpleSpectralSubtraction::clone()
{
	return new SimpleSpectralSubtraction(*this);
}

void SimpleSpectralSubtraction::operator()(std::complex<double> * const input_spectrum,const  double* const noise_spectrum)
{
#pragma omp parallel for
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
}

void SimpleSpectralSubtraction::onFFTSizeUpdate()
{

}

void SimpleSpectralSubtraction::onDataUpdate()
{

}

double SimpleSpectralSubtraction::alpha() const
{
	return _alpha;
}

void SimpleSpectralSubtraction::setAlpha(const double value)
{
	_alpha = std::max(value,  0.0);
}

double SimpleSpectralSubtraction::beta() const
{
	return _beta;
}

void SimpleSpectralSubtraction::setBeta(const double value)
{
	_beta = std::max(value,  0.0);
}
