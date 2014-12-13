#include "PositionNode.h"


PositionNode::PositionNode(std::shared_ptr<Vertex> vertex, int distance) : vertex(vertex), distance(distance)
{
}


PositionNode::~PositionNode()
{
}

int PositionNode::GetDistance()
{
	return distance;
}

std::shared_ptr<Vertex> PositionNode::GetVertex()
{
	return vertex;
}
