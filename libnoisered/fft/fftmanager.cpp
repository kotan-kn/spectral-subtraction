#include "fftmanager.h"

#include <iostream>
FFTManager::FFTManager()
{
}

FFTManager::~FFTManager()
{
	delete[] _in;
	delete[] _out;
	delete[] _spectrum;
}


double *FFTManager::input()
{
	return _in;
}

double *FFTManager::output()
{
	return _out;
}

std::complex<double> *FFTManager::spectrum()
{
	return _spectrum;
}

unsigned int FFTManager::spectrumSize()
{
	return _fftSize / 2 + 1;
}

unsigned int FFTManager::size()
{
	return _fftSize;
}

void FFTManager::updateSize(const unsigned int n)
{
	_fftSize = n;
	_in = new double[size()];
	_out = new double[size()];
	_spectrum = new std::complex<double>[spectrumSize()];
}