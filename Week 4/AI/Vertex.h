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
	bool visited;
	bool hasPill = false;
	bool hasWeapon = false;

	int x_pos, y_pos;
	int weight;
	std::weak_ptr<Vertex> parent;
	std::vector<std::shared_ptr<Edge>> edges;

public:
	Vertex(int x_pos, int y_pos, bool hasPill, bool hasWeapon);
	~Vertex();

	// Functions
	void AddObject(std::shared_ptr<Edge> edge);
	void SetVisited(bool value);
	void SetParent(std::shared_ptr<Vertex> p_parent);
	std::shared_ptr<Vertex> GetParent();

	bool IsVisited();

	// Pill methods
	bool hasNewPill();
	void setPill(bool new_status_pill);
	bool getPill();

	// Weapon methods
	bool hasNewWeapon();
	void setWeapon(bool new_status_weapon);
	bool getWeapon();
	
	std::vector<std::shared_ptr<Edge>> GetEdges();
	int getXPos();
	void setXPos(int position);
	int getYPos();
	void setYPos(int position);
	int getWeight();
};

