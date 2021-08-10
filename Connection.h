#pragma once

class Neuron;
class Connection
{

public:

	//if from connection is null, connection comes from input  
	Neuron* mTo;
	Neuron* mFrom;
	float mWeight;

	Connection();
	Connection(Neuron* to, Neuron* from);
	void adjustWeight(float weight);

};

