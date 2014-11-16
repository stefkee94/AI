#pragma once

#include <vector>
#include <memory>

#include "Edge.h"
#include "Cow.h"
#include "Hare.h"

class Vertex
{
private:
	std::vector<Edge> edges;
	bool visited;
	std::weak_ptr<Cow> cow;
	std::weak_ptr<Hare> hare;

public:
	Vertex();
	~Vertex();

	// Functions
	void AddObject(Edge edge);
	void SetVisited(bool value);
	void SetCow(std::shared_ptr<Cow> p_cow);
	void SetHare(std::shared_ptr<Hare> p_hare);

	bool IsVisited();
	std::vector<Edge> GetEdges();
	std::shared_ptr<Cow> GetCow();
	std::shared_ptr<Hare> GetHare();
};

