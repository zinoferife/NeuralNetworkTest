#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

#include "Connection.h"

//learning neural network like this
//template it on the type of input
class Neuron
{
public:
	Neuron();
	Neuron(float input, std::int32_t id);
	float output();
	void CreateConnection(Neuron* mFrom);
	void addInput(float input);
	Connection* GetConnection(std::uint32_t conn);

	const std::size_t GetNumberOfConnections() const;


	std::int32_t mId;
	float mInput;
	std::vector<Connection> mConnections;


	static float Activation;
};
