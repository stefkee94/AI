#include "Hare.h"
#include <qdir.h>
Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");
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