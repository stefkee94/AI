#pragma once

#include <vector>
class Vertex;
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
	void setPosition(Vertex dests);
	void AddDestination(Vertex destination);
};

