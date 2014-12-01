#pragma once

#include <vector>
#include <memory>

#include "Edge.h"
#include "Cow.h"
#include "Hare.h"

class Cow;
class Hare;
class Vertex
{
private:
	//std::vector<Edge> edges;
	bool visited;
	int x_pos, y_pos;
	int weight;
	std::weak_ptr<Vertex> parent;
	std::vector<std::shared_ptr<Edge>> edges;

public:
	Vertex(int x_pos, int y_pos);
	~Vertex();

	// Functions
	void AddObject(std::shared_ptr<Edge> edge);
	void SetVisited(bool value);
	void SetParent(std::shared_ptr<Vertex> p_parent);
	std::shared_ptr<Vertex> GetParent();

	bool IsVisited();
	std::vector<std::shared_ptr<Edge>> GetEdges();
	int getXPos();
	void setXPos(int position);
	int getYPos();
	void setYPos(int position);
	int getWeight();
};

