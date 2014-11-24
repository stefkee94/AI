#include "Cow.h"

Cow::Cow()
{
	img_link = "C:\\Users\\Sjoerd Nijhof\\Desktop\\KMINT_Sprites\\lemmling_Cartoon_cow.png";
}

Cow::~Cow()
{
}

void Cow::SetVertex(std::shared_ptr<Vertex> p_vertex)
{
	vertex = p_vertex;
}

std::shared_ptr<Vertex> Cow::GetVertex()
{
	return vertex;
}

QString Cow::GetImageLink()
{
	return img_link;
}