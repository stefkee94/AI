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
	owner->SetVertex(owner->GetVertex()->GetEdges()[0]->GetDestinations()[0]);
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
