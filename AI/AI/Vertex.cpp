#include "Vertex.h"


Vertex::Vertex(int x_pos, int y_pos) : x_pos(x_pos), y_pos(y_pos)
{
	visited = false;
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
	//edges.push_back(edge);
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

//std::vector<Edge> Vertex::GetEdges()
//{
//	return edges;
//}

std::shared_ptr<Cow> Vertex::GetCow()
{
	return cow.lock();
}

std::shared_ptr<Hare> Vertex::GetHare()
{
	return hare.lock();
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