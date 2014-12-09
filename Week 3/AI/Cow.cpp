#include "Cow.h"
#include <qdir.h>
#include "Graph.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");

	// Init on wandering state for the cow
	BaseUnit::ChangeState(EnumState::COW_CHASING);
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

std::vector<std::shared_ptr<Vertex>> Cow::Move(std::shared_ptr<Graph> graph)
{
	// Send behavior to state
	behavior->CheckState();
	return behavior->Move(graph);
}

void Cow::Update(std::shared_ptr<Graph> graph)
{
	behavior->Update(graph);
}

std::string Cow::GetAction()
{
	return behavior->GetAction();
}

EnumState Cow::GetState()
{
	return currentState;
}

void Cow::SetPil(bool contains_pill)
{
	pill = contains_pill;
}

bool Cow::GetPil()
{
	return pill;
}
