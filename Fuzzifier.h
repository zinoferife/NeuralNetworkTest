#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <sstream>
#include <random>
#include <cassert>
#include <chrono>

class Fuzzifier
{
public:
	class Category
	{
	public:
		enum
		{
			high = 0,
			mid = 1,
			low = 2
		};
		Category(): mHigh(0.0f), mMid(0.0f), mLow(0.0f){}
		Category(const std::string& name, float high, float mid, float low);
		std::tuple<float,float, float> getValues() const;
		float getShare(float input);
		const std::string& getName() const;
	
	private:
		float mHigh;
		float mMid;
		float mLow;
		std::string mName;
	};

	Fuzzifier();
	~Fuzzifier();

	void createCategory(const std::string& name, float high, float mid, float low);
	std::stringstream doFuzzy(const std::vector<float>& data);
	float randomNumber(float max,float min);

 

private:
	std::vector<Category> mCategories;



};

