#pragma once

#include <vector>
#include "BehaviorState.h"

class CowFindWeaponState : public BehaviorState
{
public:
	CowFindWeaponState(std::shared_ptr<MovingEntity> owner);
	~CowFindWeaponState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();
	int GetPoints(Controller* controller);
	EnumState GetType();

private:
	bool foundHare = false;
};