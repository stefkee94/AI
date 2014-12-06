#pragma once
#include "BehaviorState.h"

class HareFleeingState : public BehaviorState
{
public:
	HareFleeingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareFleeingState();

	void Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);
};

