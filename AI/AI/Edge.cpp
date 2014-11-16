#include "Edge.h"


Edge::Edge(int p_weight) : weight(p_weight)
{
}


Edge::~Edge()
{
}

int Edge::GetWeight()
{
	return weight;
}

std::vector<Vertex> Edge::GetDestinations()
{
	return destinations;
}

void Edge::AddDestination(Vertex destination)
{
	destinations.push_back(destination);
}
