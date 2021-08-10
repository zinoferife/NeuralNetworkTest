#include "Connection.h"
Connection::Connection() :mTo(nullptr), mFrom(nullptr), mWeight(0.0f) {

}

Connection::Connection(Neuron* to, Neuron* from) :
	mTo(to), mFrom(from), mWeight(0.0f) {

}

void Connection::adjustWeight(float weight)
{
	mWeight += weight;
}
