#pragma once

#include <vector>
#include <memory>
#include "Edge.h"
#include "Vertex.h"

class Graph
{
private:
	std::vector<std::shared_ptr<Vertex>> positions;
	std::vector<Vertex> closed_list;
	std::vector<Vertex> open_list;
	void Init();

public:
	Graph();
	~Graph();

	// Functions
	void Search(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> end_node);
	void FillOpenList();
};

