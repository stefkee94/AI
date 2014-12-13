#include "Hare.h"
#include <qdir.h>

Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");
	behavior = new HareWanderingState(std::shared_ptr<BaseUnit>(this));
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

std::vector<std::shared_ptr<Vertex>> Hare::Move()
{
	// Send behavior to state
	return behavior->Move();
}

void Hare::Update(Controller* controller)
{
	behavior->Update(controller);
}

std::string Hare::GetAction()
{
	return behavior->GetAction();
}

EnumState Hare::GetState()
{
	return currentState;
}

void Hare::SetPil(bool contains_pill)
{
	pill = contains_pill;
}

bool Hare::GetPil()
{
	return pill;
}