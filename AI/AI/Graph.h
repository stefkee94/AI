#pragma once

#include <vector>
#include <memory>

#include "Edge.h"
#include "Vertex.h"
#include "Cow.h"
#include "Hare.h"

class Graph
{
private:
	//std::vector<std::shared_ptr<Vertex>> positions;
	std::vector<std::shared_ptr<Vertex>> positions;
	std::vector<std::shared_ptr<Edge>> edges;

	std::vector<std::shared_ptr<Vertex>> closed_list;
	std::vector<std::shared_ptr<Vertex>> open_list;

	
	void AddVertex();
	void AddEdges(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);

public:
	Graph();
	~Graph();

	// Functions
	void Init(std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare);
	void Search(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> end_node, std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare);
	void FillOpenList(std::shared_ptr<Vertex> current_node);
	void CalculateDistance(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node);
	std::vector<std::shared_ptr<Vertex>> getPositions();
	std::vector<std::shared_ptr<Edge>> getEdges();
};

