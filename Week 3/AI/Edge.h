#pragma once

#include <vector>
#include <memory>

class Vertex;
class Edge
{
private:
	int weight;
	std::vector<std::shared_ptr<Vertex>> destinations;

public:
	Edge(int p_weight, std::shared_ptr<Vertex> dest1, std::shared_ptr<Vertex> dest2);
	~Edge();

	// Functions
	int GetWeight();
	std::vector<std::shared_ptr<Vertex>> GetDestinations();
	void setPosition(std::shared_ptr<Vertex> dests);
	void AddDestination(std::shared_ptr<Vertex> destination);
};

