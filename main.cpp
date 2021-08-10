#include "Perceptron.h"
#include <random>
#include "HopField.h"
#include "Fuzzifier.h"

int main(std::int32_t argc, std::int8_t** argv)
{
	std::vector< std::vector<float> > weights =
	{
		{0.0,-5.0,4.0,4.0},
		{-5.0,0.0,4.0,4.0},
		{4.0,4.0,0.0,-5.0},
		{4.0,4.0,-5.0,0.0}
	};

	std::vector<float> input = { 0.0,1.0,1.0,0.0 };

	HopField hFeild(input, weights);

	hFeild.update();

	for (auto& i : hFeild.GetOutput())
	{
		std::cout << i << std::endl;
	}


	/*
	Fuzzifier fuz;
	fuz.createCategory("zino", 5, 3.5, 0);
	fuz.createCategory("ferife", 7, 5, 3.5);
	fuz.createCategory("patrick", 10, 8, 6);
	fuz.createCategory("ewoma", 4, 1, 0);
	std::vector<float> data{ 0.8 , 0.7, 0.5, 9.0, 5.0, 6.0,7.0};

	std::cout << fuz.doFuzzy(data).str() << std::endl;
	*/


	return 0;
}