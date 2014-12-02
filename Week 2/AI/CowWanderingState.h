#pragma once

#include "BehaviorState.h"

class CowWanderingState : public BehaviorState
{
public:
	CowWanderingState(std::shared_ptr<Cow> owner);
	~CowWanderingState();

	void Move(std::shared_ptr<Graph> graph);
	void Update();
	void CheckState();

private:
	bool hasEatenPill;
	//std::shared_ptr<Vertex> current_vertex;
};

