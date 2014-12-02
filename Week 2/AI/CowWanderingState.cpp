#include "CowWanderingState.h"
#include <iostream>
#include "Cow.h"

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
	owner->SetVertex(positions.at(0) != owner->GetVertex() ? positions.at(0) : positions.at(1));
}

void CowWanderingState::Update()
{
	//Logic for update cow in the wandering state
}

void CowWanderingState::CheckState()
{
	//TODO : IF PILL FOUND CHANGE STATE
	//if (hasEatenPill)
		//owner->ChangeState(EnumState::COW_CHASING);
}
