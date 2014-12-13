#include "HareFleeingState.h"

HareFleeingState::HareFleeingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner), counter(2)
{
}

std::vector<std::shared_ptr<Vertex>> HareFleeingState::Move()
{
	return std::vector<std::shared_ptr<Vertex>>();
}

void HareFleeingState::Update(Controller* controller)
{

}

std::string HareFleeingState::GetAction()
{
	return "fleeing from the cow";
}

void HareFleeingState::CheckState()
{
}

HareFleeingState::~HareFleeingState()
{
}
