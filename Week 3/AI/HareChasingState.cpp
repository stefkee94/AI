#include "HareChasingState.h"
#include "Graph.h"

HareChasingState::HareChasingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareChasingState::~HareChasingState()
{
}
void HareChasingState::Move(std::shared_ptr<Graph> graph)
{
	// in chasing mode, move the cow to other place and change state to wandering
	if (owner->GetVertex() == graph->GetCowPosition())
		shotCow = true;
		
}

void HareChasingState::Update(std::shared_ptr<Graph> graph)
{

}

void HareChasingState::CheckState()
{
	if (shotCow)
		owner->ChangeState(EnumState::HARE_WANDERING);
}
