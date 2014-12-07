#pragma once

#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class HareSearchingWeaponState : public BehaviorState
{
public:
	HareSearchingWeaponState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareSearchingWeaponState();

	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);
};

