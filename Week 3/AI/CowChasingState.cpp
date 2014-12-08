#include "CowChasingState.h"
#include "Graph.h"

CowChasingState::CowChasingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


CowChasingState::~CowChasingState()
{
}

std::vector<std::shared_ptr<Vertex>> CowChasingState::Move(std::shared_ptr<Graph> graph)
{
	//Logic for move the cow in the chasing state
	std::shared_ptr<Vertex> cow_pos = owner->GetVertex();
	std::shared_ptr<Vertex> hare_pos = graph->GetHarePosition();

	if (cow_pos != hare_pos)
		return graph->GetRoute(cow_pos, hare_pos);
	else
	{
		//foundHare = true;
		//CheckState();
		return std::vector<std::shared_ptr<Vertex>>();
	}
}

void CowChasingState::Update(std::shared_ptr<Graph> graph)
{

}

std::string CowChasingState::GetAction()
{
	return "chasing the hare";
}

void CowChasingState::CheckState()
{
	// If cow found hare, change status to wandering
	/*if (foundHare)
	{
		foundHare = false;
		owner->ChangeState(EnumState::COW_WANDERING);
	}*/
}
