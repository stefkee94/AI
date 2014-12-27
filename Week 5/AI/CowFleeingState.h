#pragma once

#include <vector>
#include "BehaviorState.h"

class CowFleeingState : public BehaviorState
{
public:
	CowFleeingState(std::shared_ptr<MovingEntity> owner);
	~CowFleeingState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();
	int GetPoints(Controller* controller);
	
private:
	bool foundHare = false;
};