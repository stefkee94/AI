#include "CowChasingState.h"
#include "Cow.h"
#include "Graph.h"

CowChasingState::CowChasingState(std::shared_ptr<Cow> owner) : BehaviorState(owner)
{
	//this->owner = owner;
	//this->graph = graph;
}


CowChasingState::~CowChasingState()
{
}

void CowChasingState::Move(std::shared_ptr<Graph> graph)
{
	//Logic for move the cow in the chasing state
	std::shared_ptr<Vertex> cow_pos = owner->GetVertex();
	std::shared_ptr<Vertex> hare_pos = graph->GetHarePosition();
	graph->GetRoute(cow_pos, hare_pos);
	foundHare = true;
}

void CowChasingState::Update()
{
	// Logic for update the cow in the chasing state
}

void CowChasingState::CheckState()
{
	// If cow found hare, change status to wandering
	if (foundHare)
	{
		owner->ChangeState(EnumState::COW_WANDERING);
		//foundHare = false;
	}
		
}
