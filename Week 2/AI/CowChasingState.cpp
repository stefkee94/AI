#include "CowChasingState.h"

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
}

void CowChasingState::Update()
{
	// Logic for update the cow in the chasing state
}

void CowChasingState::CheckState()
{

}
