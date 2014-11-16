#pragma once

#include <vector>
#include "Edge.h"
#include "Vertex.h"

class Graph
{
private:
	std::vector<Vertex> positions;
	std::vector<Vertex> closed_list;
	std::vector<Vertex> open_list;
	void Init();

public:
	Graph();
	~Graph();

	// Functions
	void Search();
};

