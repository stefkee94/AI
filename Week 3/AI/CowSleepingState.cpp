#include "CowSleepingState.h"
#include "Graph.h"

CowSleepingState::CowSleepingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}

std::vector<std::shared_ptr<Vertex>> CowSleepingState::Move(std::shared_ptr<Graph> graph)
{
	//DO NOTHING BECAUSE IT'S SLEEPING
	return std::vector<std::shared_ptr<Vertex>>();
}

void CowSleepingState::Update(std::shared_ptr<Graph> graph)
{

}

std::string CowSleepingState::GetAction()
{
	return "is sleeping";
}

void CowSleepingState::CheckState()
{
	
}

CowSleepingState::~CowSleepingState()
{
}
