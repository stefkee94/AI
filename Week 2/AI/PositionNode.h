#pragma once

#include <memory>
#include "Vertex.h"

class PositionNode
{
private:
	int distance;
	std::shared_ptr<Vertex> vertex;

public:
	PositionNode(std::shared_ptr<Vertex> vertex, int distance);
	~PositionNode();

	int GetDistance();
	std::shared_ptr<Vertex> GetVertex();
};

