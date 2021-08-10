#include "Perceptron.h"
std::ostream& operator<<(std::ostream& os, Perceptron& network)
{
	os << network.DisplayNetork();
	for (auto& i : network.GetResult())
	{
		os << i << std::endl;

	}
	return os;
}


Perceptron::Perceptron(std::int32_t neuronsPerOutputLayer)
	:mInputLayer(nullptr), mOutputLayer(nullptr), mResult(neuronsPerOutputLayer)
{

}

void Perceptron::run()
{
	for (std::int32_t i = 0; i < mResult.size(); i++)
	{
		mResult[i] = mOutputLayer->mNeurons[i].output();
	}
}

void Perceptron::CreateLayersInput(float* input, std::int32_t neuronsPerLayer)
{
	mInputLayer = new Layer(neuronsPerLayer);
	mLayers.push_back(mInputLayer);

	mInputLayer->CreateNeurons(input);

}

void Perceptron::CreateLayersHidden(std::int32_t neuronsPerLayer)
{
	Layer* layer = new Layer(neuronsPerLayer);
	if (mLayers.empty())
	{
		std::cout << "Cannot create a hidden layer without creating an input layer " << std::endl;
		return;
	}
	if (mOutputLayer)
	{
		std::cout << "Cannot add Hidden Layer after an OutputLayer" << std::endl;
		return;
	}
	
	mLayers[mLayers.size() - 1]->ConnectTolayer(*layer);
	mLayers.push_back(layer);
	mLayers[mLayers.size() - 1]->CreateNeurons(nullptr);
}

void Perceptron::CreateLayersOutput(std::int32_t neuronsPerLayer)
{
	if (mInputLayer == nullptr)
	{
		std::cout << "Cannot create an OutputLyer without creating at least an input layer" << std::endl;
		return;
	}
	mOutputLayer = new Layer(neuronsPerLayer);
	mLayers[mLayers.size() - 1]->ConnectTolayer(*mOutputLayer);
	mLayers.push_back(mOutputLayer);
	mOutputLayer->CreateNeurons(nullptr);
}

void Perceptron::ModifyNetWork(std::uint32_t layer, std::uint32_t neuron, std::uint32_t connection, float modifyWeight)
{
	Connection* connectionToMod = GetLayer(layer)->GetNeuron(neuron)->GetConnection(connection);
	connectionToMod->adjustWeight(modifyWeight);
}


Layer* Perceptron::GetLayer(std::uint32_t layer) const 
{
	assert((layer >= 0 && layer < mLayers.size()));
	if (layer == 0) return mInputLayer;
	if (layer == (mLayers.size() - 1)) return mOutputLayer;
	return mLayers[layer];

}

const std::vector<float>& Perceptron::GetResult() const
{
	return mResult;
}

std::string Perceptron::DisplayNetork()
{
	std::stringstream out;
	for (std::uint32_t l = 0; l < mLayers.size(); l++)
	{
		out << "Layer " << std::to_string(l) << std::endl;
		for (std::uint32_t n = 0; n < mLayers[l]->mNumOfNeurons; n++)
		{
			out << "\t" << "Neuron " << mLayers[l]->GetNeuron(n)->mId << std::endl;
			for (std::uint32_t c = 0; c < mLayers[l]->GetNeuron(n)->GetNumberOfConnections(); c++)
			{
				std::string iP = mLayers[l]->GetNeuron(n)->mConnections[c].mFrom ? std::to_string(mLayers[l]->GetNeuron(n)->mConnections[c].mFrom->mId) : "input value";
				out << "\t\t" << "From: " << iP << " Weight:" << mLayers[l]->GetNeuron(n)->mConnections[c].mWeight << " Input " << mLayers[l]->GetNeuron(n)->mInput << std::endl;
			}
		}
	}

	return out.str();
}


Perceptron::~Perceptron()
{
	for (auto& i : mLayers)
	{
		delete i;
	}
	mLayers.clear();
	mResult.clear();

	mOutputLayer = nullptr;
	mInputLayer = nullptr;
}

