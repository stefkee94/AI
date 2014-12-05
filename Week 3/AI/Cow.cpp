#include "Cow.h"
#include <qdir.h>
#include "Graph.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	// Init on wandering state for the cow
	//behavior = std::make_shared<CowWanderingState>(std::shared_ptr<Cow>(this));
	BaseUnit::ChangeState(EnumState::COW_WANDERING);
	//this->graph = graph;
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

void Cow::Move(std::shared_ptr<Graph> graph)
{
	// Send behavior to state
	behavior->CheckState();
	behavior->Move(graph);
}

EnumState Cow::GetState()
{
	return currentState;
}
