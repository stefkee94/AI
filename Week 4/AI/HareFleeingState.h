#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class HareFleeingState : public BehaviorState
{
public:
	HareFleeingState(std::shared_ptr<MovingEntity> owner);
	virtual ~HareFleeingState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();

private:
	double timer;
	double start_time;
};

