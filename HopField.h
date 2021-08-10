#pragma once
#include <vector>


//single layer network
class HopField
{
public:
	HopField(const std::vector<float>& input , const std::vector<std::vector<float> >& weights);

	void update();

	const std::vector<float>& GetOutput() const;
private:

	float DotProduct(std::int32_t i );

	std::vector < std::vector < float > > mNeuronWeight;
	std::vector<float> mOutput;
	std::vector<float> mInput;
	float mThreshold;
};

