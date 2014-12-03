#pragma once
#include "BehaviorState.h"

class HareWanderingState : public BehaviorState
{
public:
	HareWanderingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareWanderingState();

	void Move(std::shared_ptr<Graph> graph);
	void Update();
	void CheckState();

private:
	bool hasWeapon = false;
};

