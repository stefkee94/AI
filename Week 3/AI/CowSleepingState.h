#pragma once
#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class CowSleepingState : public BehaviorState
{
public:
	CowSleepingState(std::shared_ptr<BaseUnit> owner);
	virtual ~CowSleepingState();

	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void MoveCow(std::vector<std::shared_ptr<Vertex>> new_position);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);
	std::string GetAction();
};

