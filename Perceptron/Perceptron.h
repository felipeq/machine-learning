#pragma once
#include "Constants.h"
class Perceptron
{
public:
	static std::vector<double> weights;
	static double threshold;
	static void initializePerceptron()
	{
		// we need 2 weights for 2 dimensional training input
		for (int i = 0; i < CIRCLE_AMOUNT + 1; i++)
		{
			weights.push_back((double)rand() / (RAND_MAX));
		}
		threshold = (double)rand() / (RAND_MAX);
	}

};
std::vector<double> Perceptron::weights;
double Perceptron::threshold;

