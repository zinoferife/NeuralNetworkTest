#include "Neuron.h"

float Neuron::Activation = 2.0f;

Neuron::Neuron() :
	mInput(0.0f), mId(0) {
}


Neuron::Neuron(float input, std::int32_t id) :
	mInput(input), mId(id) {

}

void Neuron::addInput(float input)
{
	mInput += input;
}


void Neuron::CreateConnection(Neuron* mFrom)
{
	Connection conn(this, mFrom);
	mConnections.push_back(conn);
}
Connection* Neuron::GetConnection(std::uint32_t conn)
{
	assert((conn >= 0 && conn < mConnections.size()));
	return &mConnections[conn];
}

float Neuron::output()
{
	float ret;
	std::for_each(mConnections.begin(), mConnections.end(), [&](Connection& conn) {
		if (conn.mFrom != nullptr)
		{
			ret += conn.mWeight * conn.mFrom->output();
		}
		else
		{
			ret += conn.mWeight * mInput;
		}
		});

	//activation, threshold
	return ret >= Activation ? 1.0 : 0.0;
}

const std::size_t Neuron::GetNumberOfConnections() const
{
	return mConnections.size();
}
