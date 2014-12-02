#include "Vertex.h"

Vertex::Vertex(int x_pos, int y_pos, bool hasPill, bool hasWeapon) : x_pos(x_pos), y_pos(y_pos), hasPill(hasPill), hasWeapon(hasWeapon)
{
	visited = false;
	this->hasPill = hasPill;
	this->hasWeapon = hasWeapon;
	weight = rand() % 100;
}

Vertex::~Vertex()
{
}

void Vertex::SetVisited(bool value)
{
	visited = value;
}

void Vertex::AddObject(std::shared_ptr<Edge> edge)
{
	edges.push_back(edge);
}

bool Vertex::IsVisited()
{
	return visited;
}

bool Vertex::hasNewPill()
{
	return hasPill;
}

void Vertex::setPill(bool new_status_pill)
{
	hasPill = new_status_pill;
}

bool Vertex::getPill()
{
	return hasPill;
}

bool Vertex::hasNewWeapon()
{
	return hasWeapon;
}

void Vertex::setWeapon(bool new_status_weapon)
{
	hasWeapon = new_status_weapon;
}

bool Vertex::getWeapon()
{
	return hasWeapon;
}

std::vector<std::shared_ptr<Edge>> Vertex::GetEdges()
{
	return edges;
}

std::shared_ptr<Vertex> Vertex::GetParent()
{
	return parent.lock();
}

void Vertex::SetParent(std::shared_ptr<Vertex> p_parent)
{
	parent = p_parent;
}

int Vertex::getXPos()
{
	return x_pos;
}

void Vertex::setXPos(int position)
{
	x_pos = position;
}

int Vertex::getYPos()
{
	return y_pos;
}

void Vertex::setYPos(int position)
{
	y_pos = position;
}

int Vertex::getWeight()
{
	return weight;
}