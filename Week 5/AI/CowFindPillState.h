#pragma once

#include <vector>
#include "BehaviorState.h"

class CowFindPillState : public BehaviorState
{
public:
	CowFindPillState(std::shared_ptr<MovingEntity> owner);
	~CowFindPillState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();
	int GetPoints(Controller* controller);
	EnumState GetType();

private:
	bool foundHare = false;
};