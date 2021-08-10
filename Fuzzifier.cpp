#include "Fuzzifier.h"
Fuzzifier::Fuzzifier()
{
	//Creates a simple Fuzzifier application
}


Fuzzifier::~Fuzzifier()
{
	
}

void Fuzzifier::createCategory(const std::string& name, float high, float mid, float low)
{
	mCategories.emplace_back(name, high, mid, low);
}

std::stringstream Fuzzifier::doFuzzy(const std::vector<float>& data)
{
	std::vector<float>::const_iterator data_;
	std::vector<float> RelPob;
	float total = 0.0f;
	std::stringstream out;

	data_ = data.begin();
	while (data_ != data.end()) {
		for (auto category = mCategories.begin(); category != mCategories.end(); category++)
		{
			auto cal = 100 * category->getShare(*data_);
			total += cal;
			RelPob.push_back(cal);
		}
		assert(total != 0.0f);
		float randNum = randomNumber(total, 0.0f);
		float runTotal = RelPob.front();
		std::size_t count = 0;

		//randomly select category, 
		while ((runTotal < randNum) && (count != mCategories.size()))
		{
			runTotal += RelPob[++count];
		}
		out << "Output Fuzzy category is: " << mCategories[count].getName() << "... \n";
		out << "Category\t" << "Membership\n";
		for (int i = 0; i < mCategories.size(); i++)
		{
			out << mCategories[i].getName() << "\t\t" << (RelPob[i] / total) << "\n";
		}

		out << "\n\n";

		RelPob.clear();
		total = 0.0f;
		data_++;
	}

	return out;
}

float Fuzzifier::randomNumber(float max, float min)
{
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_real_distribution<float> distro(min, max);
	return distro(gen);
}

Fuzzifier::Category::Category(const std::string& name, float high, float mid, float low)
	: mHigh(high),mMid(mid),mLow(low),mName(name)
{
	//creates a category
}

std::tuple<float, float, float> Fuzzifier::Category::getValues() const
{
	return { mHigh,mMid,mLow };
}

const std::string& Fuzzifier::Category::getName() const
{
	return mName;
}


float Fuzzifier::Category::getShare(float value)
{
	if (value <= mLow || value >= mHigh) return 0;

	float ret = 0.0f;
	float higMid = mHigh - mMid;
	float lowMid = mMid - mLow;
	if (value > mMid)
	{
		ret = (mHigh - value) / higMid;
	}
	else if (value == mMid) ret = 1.0;
	else
	{
		ret = (value - mLow) /lowMid;
	}
	return ret;
}

