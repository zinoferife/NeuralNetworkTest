#include "HopField.h"

HopField::HopField(const std::vector<float>& input , const std::vector<std::vector<float> >& weights)
: mThreshold(0.0){
	mInput = input;
	mNeuronWeight = weights;
}

void HopField::update()
{
	mOutput = mInput;
	std::int32_t i = 0;
	float outI = 0.0;
	while (true)
	{
		float value = DotProduct(i);
		outI = value > mThreshold ? 1.0 : 0.0;
		mOutput[i] = outI;
		
		if (mOutput == mInput) break;
		else
		{
			mInput[i] = outI;
		}
		if (++i >= mInput.size()) i = 0;
	}

}

float HopField::DotProduct(std::int32_t i)
{
	float ret = 0.0f;
	for (int j = 0; j < mNeuronWeight[i].size(); j++)
	{
		ret += mInput[j] * mNeuronWeight[i][j];
	}

	return ret;
}
const std::vector<float>& HopField::GetOutput() const
{
	return mOutput;
}