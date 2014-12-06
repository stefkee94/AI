#pragma once

#include "BehaviorState.h"
class CowWanderingState : public BehaviorState
{
public:
	CowWanderingState(std::shared_ptr<BaseUnit> owner);
	~CowWanderingState();

	void Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);

private:
	bool hasEatenPill = false;
};

