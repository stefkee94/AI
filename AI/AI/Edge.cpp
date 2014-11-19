#include "Edge.h"
#include "Vertex.h"

Edge::Edge(int p_weight, Vertex dest1, Vertex dest2) : weight(p_weight)
{
	destinations.push_back(dest1);
	destinations.push_back(dest2);
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
