#pragma once
#include "Layer.h"
#include <sstream>

//The network
class Perceptron
{
public:
	typedef std::function<void(float* weights)> RuleFunc;

	Perceptron(std::int32_t neuronsPerOutputLayer);

	void run();
	void CreateLayersInput(float* input, std::int32_t neuronsPerLayer);
	void CreateLayersHidden(std::int32_t neuronsPerLayer);
	void CreateLayersOutput(std::int32_t neuronsPerLayer);
	void ModifyNetWork(std::uint32_t layer, std::uint32_t neuron, std::uint32_t connection, float modifyWeight);
	Layer* GetLayer(std::uint32_t layer) const;
	const std::vector<float>& GetResult() const;
	std::string DisplayNetork();


	~Perceptron();

private:
	Layer* mOutputLayer;
	Layer* mInputLayer;
	std::vector<Layer*> mLayers;
	std::vector<float> mResult;
	//traing rule, on how to update the weight
	//RuleFunc mRuleFunc;

};

std::ostream& operator<<(std::ostream& os, Perceptron& network);

