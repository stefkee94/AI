#include "Edge.h"
#include "Vertex.h"

Edge::Edge(int p_weight, std::shared_ptr<Vertex> dest1, std::shared_ptr<Vertex> dest2) : weight(p_weight)
{
	setPosition(dest1);
	setPosition(dest2);
}

Edge::~Edge()
{
}

int Edge::GetWeight()
{
	return weight;
}

std::vector<std::shared_ptr<Vertex>> Edge::GetDestinations()
{
	return destinations;
}

void Edge::AddDestination(std::shared_ptr<Vertex> destination)
{
	destinations.push_back(destination);
}

void Edge::setPosition(std::shared_ptr<Vertex> pos)
{
	pos->setXPos(pos->getXPos() + 10);
	pos->setYPos(pos->getYPos() + 10);
	destinations.push_back(pos);
}
