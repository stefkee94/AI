#pragma once

#include <vector>
#include "Vertex.h"

class Edge
{
private:
	int weight;
	std::vector<Vertex> destinations;

public:
	Edge(int p_weight, Vertex dest1, Vertex dest2);
	~Edge();

	// Functions
	int GetWeight();
	std::vector<Vertex> GetDestinations();
	void AddDestination(Vertex destination);
};

