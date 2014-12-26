#include "CowHideState.h"
#include "Controller.h"

CowHideState::CowHideState(std::shared_ptr<MovingEntity> owner) : BehaviorState(owner)
{
	owner->SetMaxSpeed(0.5);
}


CowHideState::~CowHideState()
{
}

void CowHideState::Update(Controller* controller, double time_elapsed)
{
}

std::string CowHideState::GetAction()
{
	return "hiding";
}

void CowHideState::CheckState()
{
}
