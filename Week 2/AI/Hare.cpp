#include "Hare.h"
#include <qdir.h>
#include "Graph.h"

Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");

	// Set Hare state
	//ChangeState(EnumState::HARE_WANDERING);
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

void Hare::Move(std::shared_ptr<Graph> graph)
{
	// Send behavior to state
	//behavior->CheckState();
	//behavior->Move(graph);
}

void Hare::Update()
{
	//TODO
}

void Hare::ChangeState(EnumState new_state)
{
	//switch (new_state)
	//{
	//	case EnumState::HARE_WANDERING:
	//		//behavior = new HareWanderingState(std::shared_ptr<Hare>(this));
	//		//currentState = EnumState::HARE_WANDERING;
	//		break;
	//	case EnumState::HARE_CHASING:
	//		//behavior = new HareChasingState(std::shared_ptr<Hare>(this));
	//		//currentState = EnumState::HARE_WANDERING;
	//}
}

EnumState Hare::GetState()
{
	return currentState;
}