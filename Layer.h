#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
//learning neural network like this

#include "Neuron.h"


class Layer
{
public:
	Layer();
	Layer(std::int32_t numNeurons);
	void ConnectTolayer(Layer& layer);

	//input should be the same count as the number of neuron if not null
	void CreateNeurons(float* input);
	Neuron* GetNeuron(std::uint32_t neuron);

	~Layer();


	std::int32_t mNumOfNeurons;
	Neuron* mNeurons;

	static std::uint32_t NeuronID;
};
