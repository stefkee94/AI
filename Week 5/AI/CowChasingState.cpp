#include "CowChasingState.h"
#include "Controller.h"
#include "Graph.h"

CowChasingState::CowChasingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


CowChasingState::~CowChasingState()
{
}

std::vector<std::shared_ptr<Vertex>> CowChasingState::Move(std::shared_ptr<Graph> graph)
{
	if (!foundHare)
	{
		//Logic for move the cow in the chasing state
		std::shared_ptr<Vertex> cow_pos = owner->GetVertex();
		std::shared_ptr<Vertex> hare_pos = graph->GetHarePosition();

		return graph->GetRoute(cow_pos, hare_pos);
	}
	else
	{
		foundHare = false;
		return std::vector<std::shared_ptr<Vertex>>();
	}
}

void CowChasingState::Update(Controller* controller, std::shared_ptr<Graph> graph)
{
	std::shared_ptr<Hare> hare = controller->GetHare();
	if (owner->GetVertex() == hare->GetVertex() && !hare->GetPil())
	{
		std::cout << "The hare is caught" << std::endl;
		controller->RespawnHare();

		foundHare = true;
	}
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
