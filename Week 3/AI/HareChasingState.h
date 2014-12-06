#pragma once
#include "BehaviorState.h"

class HareChasingState : public BehaviorState
{
public:
	HareChasingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareChasingState();

	void Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);

private:
	bool shotCow = false;
};

