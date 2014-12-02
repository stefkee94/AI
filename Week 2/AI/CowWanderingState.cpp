#include "CowWanderingState.h"
#include "Cow.h"
#include "Graph.h"
CowWanderingState::CowWanderingState(std::shared_ptr<Cow> owner) : BehaviorState(owner)
{
	//this->owner = owner;
	//this->current_vertex = current_vertex;
}


CowWanderingState::~CowWanderingState()
{
}

//Logic for moving cow in the wandering state
void CowWanderingState::Move(std::shared_ptr<Graph> graph)
{
	// Always get first item to walk
	std::vector<std::shared_ptr<Edge>> edges = owner->GetVertex()->GetEdges();
	std::vector<std::shared_ptr<Vertex>> positions = edges.at(Utils::RandomNumber(edges.size() - 1))->GetDestinations();
	std::shared_ptr<Vertex> next_pos;
	// Get next vertex
	if (positions.at(0) != owner->GetVertex())
		next_pos = positions.at(0);
	else
		next_pos = positions.at(1);

	// Get route from owner vertex to next position
	graph->GetRoute(owner->GetVertex(), next_pos);
	graph->ClearRoute();
}

void CowWanderingState::Update()
{
	//Logic for update cow in the wandering state
}

void CowWanderingState::CheckState()
{
	//TODO : IF PILL FOUND CHANGE STATE
	if (hasEatenPill)
	{
		
		owner->ChangeState(EnumState::COW_CHASING);
		//hasEatenPill = false;
	}
		
}
