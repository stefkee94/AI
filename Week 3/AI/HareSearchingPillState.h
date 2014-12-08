#pragma once

#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class HareSearchingPillState : public BehaviorState
{
public:
	HareSearchingPillState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareSearchingPillState();

	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);
};
