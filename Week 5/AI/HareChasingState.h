#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class HareChasingState : public BehaviorState
{
public:
	HareChasingState(std::shared_ptr<MovingEntity> owner);
	virtual ~HareChasingState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();
	int GetPoints(Controller* controller);
};

