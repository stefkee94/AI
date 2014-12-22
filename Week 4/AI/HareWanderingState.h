#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class HareWanderingState : public BehaviorState
{
public:
	HareWanderingState(std::shared_ptr<MovingEntity> owner);
	virtual ~HareWanderingState();

	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();

private:
	bool hasWeapon = false;
};

