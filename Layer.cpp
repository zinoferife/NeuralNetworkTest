#include "Layer.h"
std::uint32_t Layer::NeuronID = 0;

Layer::Layer():mNeurons(nullptr), mNumOfNeurons(0) {

}
Layer::Layer(std::int32_t numNeurons):mNumOfNeurons(numNeurons) {
	mNeurons = new Neuron[mNumOfNeurons];
}

void Layer::ConnectTolayer(Layer& layer)
{
	for (std::int32_t i = 0; i < mNumOfNeurons; i++)
	{
		for (std::int32_t j = 0; j < layer.mNumOfNeurons; j++)
		{
			layer.mNeurons[j].CreateConnection(&mNeurons[i]);
		}
	}
}

void Layer::CreateNeurons(float* input)
{
	for (std::int32_t i = 0; i < mNumOfNeurons; i++)
	{
		mNeurons[i].mId = ++NeuronID;

		//input layer, also give it a connection to the outside of the neuron
		if (input != nullptr)
		{
			mNeurons[i].addInput(input[i]);
			mNeurons[i].CreateConnection(nullptr);
		}
	}
}


Neuron* Layer::GetNeuron(std::uint32_t neuron)
{
	assert((neuron >= 0 && neuron < mNumOfNeurons));
	return &mNeurons[neuron];
}

Layer::~Layer()
{
	if (mNeurons)
		delete[] mNeurons;

	mNeurons = nullptr;
	mNumOfNeurons = 0;
}