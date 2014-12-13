#pragma once

#include <vector>
#include <map>
#include <memory>

#include "Edge.h"
#include "Vertex.h"
#include "Cow.h"
#include "Hare.h"
#include "Utils.h"
#include "PositionNode.h"

class Graph
{
private:
	//std::vector<std::shared_ptr<Vertex>> positions;
	std::vector<std::shared_ptr<Vertex>> positions;
	std::vector<std::shared_ptr<Edge>> edges;

	std::vector<std::shared_ptr<Vertex>> closed_list;
	std::vector<PositionNode> open_list;

	std::vector<int> distances;

	void AddVertex(int i);
	void AddEdges(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end);

	int EstimateDistance(std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node);
	void FillOpenList(std::vector<PositionNode> ordered_list);
	std::vector<std::shared_ptr<Vertex>> CreateRoute();
	std::shared_ptr<Hare> hare;
	std::shared_ptr<Cow> cow;
public:
	Graph();
	~Graph();

	// Functions
	void Init(std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare);
	
	std::vector<std::shared_ptr<Vertex>> GetRoute(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node);

	std::vector<std::shared_ptr<Vertex>> getPositions();
	std::vector<std::shared_ptr<Edge>> getEdges();
	std::vector<std::shared_ptr<Vertex>> GetShortestChaseRoute();
	std::vector<std::shared_ptr<Vertex>> CreateWanderingRoute();
	void ClearRoute();

	std::shared_ptr<Vertex> GetHarePosition();
	std::shared_ptr<Vertex> GetCowPosition();

	void MoveHare(std::shared_ptr<Hare> hare);
	void MoveCow(std::shared_ptr<Cow> cow);
};

