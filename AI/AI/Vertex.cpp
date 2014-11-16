#include "Vertex.h"


Vertex::Vertex()
{
}


Vertex::~Vertex()
{
}

void Vertex::SetVisited(bool value)
{
	visited = value;
}

void Vertex::AddObject(Edge edge)
{
	edges.push_back(edge);
}

void Vertex::SetCow(std::shared_ptr<Cow> p_cow)
{
	cow = p_cow;
}

void Vertex::SetHare(std::shared_ptr<Hare> p_hare)
{
	hare = p_hare;
}

bool Vertex::IsVisited()
{
	return visited;
}

std::vector<Edge> Vertex::GetEdges()
{
	return edges;
}

std::shared_ptr<Cow> Vertex::GetCow()
{
	return cow.lock();
}

std::shared_ptr<Hare> Vertex::GetHare()
{
	return hare.lock();
}