#include "Hare.h"
#include <qdir.h>
#include "Graph.h"

Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");

	// Set Hare state
	BaseUnit::ChangeState(EnumState::HARE_WANDERING);
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

std::vector<std::shared_ptr<Vertex>> Hare::Move(std::shared_ptr<Graph> graph)
{
	// Send behavior to state
	return behavior->Move(graph);
}

void Hare::Update(std::shared_ptr<Graph> graph)
{
	behavior->Update(graph);
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