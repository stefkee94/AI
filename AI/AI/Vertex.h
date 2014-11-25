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
	std::vector<std::shared_ptr<Edge>> edges;
	std::weak_ptr<Cow> cow;
	std::weak_ptr<Hare> hare;

public:
	Vertex(int x_pos, int y_pos);
	~Vertex();

	// Functions
	void AddObject(std::shared_ptr<Edge> edge);
	void SetVisited(bool value);
	void SetCow(std::shared_ptr<Cow> p_cow);
	void SetHare(std::shared_ptr<Hare> p_hare);

	bool IsVisited();
	std::vector<std::shared_ptr<Edge>> GetEdges();
	std::shared_ptr<Cow> GetCow();
	std::shared_ptr<Hare> GetHare();
	int getXPos();
	void setXPos(int position);
	int getYPos();
	void setYPos(int position);
	int getWeight();
};

