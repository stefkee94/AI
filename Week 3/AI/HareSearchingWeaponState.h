#pragma once
#include "BehaviorState.h"

class HareSearchingWeaponState : public BehaviorState
{
public:
	HareSearchingWeaponState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareSearchingWeaponState();

	void Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);
};

