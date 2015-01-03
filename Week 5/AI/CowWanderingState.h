#pragma once

#include <vector>
#include "BehaviorState.h"
#include "CowFindPillState.h"
#include "CowFindWeaponState.h"
#include "CowHideState.h"
#include "CowFleeingState.h"

class Utils;
class CowWanderingState : public BehaviorState
{
public:
	CowWanderingState(std::shared_ptr<MovingEntity> owner);
	~CowWanderingState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();
	int GetPoints(Controller* controller);
	EnumState GetType();

private:
	bool foundHare = false;
};