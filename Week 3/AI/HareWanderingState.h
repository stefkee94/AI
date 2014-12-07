#pragma once

#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class HareWanderingState : public BehaviorState
{
public:
	HareWanderingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareWanderingState();

	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void CheckState();
	bool IsCowInRange(std::shared_ptr<Graph> graph);
	void Update(std::shared_ptr<Graph> graph);

private:
	bool hasWeapon = false;
};

