#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class HareWanderingState : public BehaviorState
{
public:
	HareWanderingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareWanderingState();

	std::vector<std::shared_ptr<Vertex>> Move();
	void CheckState();
	void Update(Controller* controller);
	std::string GetAction();

private:
	bool hasWeapon = false;
};

