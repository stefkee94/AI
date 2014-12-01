#include "Vertex.h"

Vertex::Vertex(int x_pos, int y_pos) : x_pos(x_pos), y_pos(y_pos)
{
	visited = false;
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