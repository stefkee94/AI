#pragma once

#include <vector>
#include "BehaviorState.h"

class CowHideState : public BehaviorState
{
public:
	CowHideState(std::shared_ptr<MovingEntity> owner);
	~CowHideState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();
	int GetPoints(Controller* controller);
	EnumState GetType();

private:
	bool foundHare = false;
};