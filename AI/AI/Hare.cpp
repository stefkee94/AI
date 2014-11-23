#include "Hare.h"

Hare::Hare()
{
	img_link = "C:\\Users\\Sjoerd\\Pictures\\KMINT_Sprites\\rabbit-3.png";
}

Hare::~Hare()
{
}

void Hare::SetVertex(std::shared_ptr<Vertex> p_vertex)
{
	vertex = p_vertex;
}

std::shared_ptr<Vertex> Hare::GetVertex()
{
	return vertex;
}

QString Hare::GetImageLink()
{
	return img_link;
}