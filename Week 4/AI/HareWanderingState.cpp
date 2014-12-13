#include "HareWanderingState.h"
#include "Controller.h"

HareWanderingState::HareWanderingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareWanderingState::~HareWanderingState()
{
}

std::vector<std::shared_ptr<Vertex>> HareWanderingState::Move()
{
	return std::vector<std::shared_ptr<Vertex>>();
}

void HareWanderingState::Update(Controller* controller)
{
	
}

std::string HareWanderingState::GetAction()
{
	return "wandering in the field";
}

void HareWanderingState::CheckState()
{
	
}
