#pragma once

#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class CowWanderingState : public BehaviorState
{
public:
	CowWanderingState(std::shared_ptr<BaseUnit> owner);
	~CowWanderingState();

	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(Controller* controller, std::shared_ptr<Graph> graph);
	std::string GetAction();

private:
	bool hasEatenPill = false;
};

