#include "CowHideState.h"
#include "Controller.h"
#include "Utils.h"

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

int CowHideState::GetPoints(Controller* controller)
{
	if (owner->HasPill())
	{
		owner->AddPoints(1);
		controller->RespawnCow();
		controller->RespawnHare();
	}
	else if (owner->HasWeapon())
	{
		controller->GetHare()->SetPosition(QVector2D(Utils::RandomNumber(controller->GetWidth()), Utils::RandomNumber(controller->GetHeight())));
		owner->SetWeapon(false);
		owner->SetState(new CowWanderingState(owner));
	}
	else
	{
		controller->RespawnCow();
		controller->RespawnHare();
		owner->SetState(new CowWanderingState(owner));
	}
	return 0;
}