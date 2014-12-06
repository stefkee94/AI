#pragma once
#include "BehaviorState.h"

class HareWanderingState : public BehaviorState
{
public:
	HareWanderingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareWanderingState();

	void Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);

private:
	bool hasWeapon = false;
};

