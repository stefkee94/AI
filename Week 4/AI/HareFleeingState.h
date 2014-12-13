#pragma once

#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class HareFleeingState : public BehaviorState
{
public:
	HareFleeingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareFleeingState();

	std::vector<std::shared_ptr<Vertex>> Move();
	void CheckState();
	void Update(Controller* controller);
	std::string GetAction();

private:
	int counter;
};

