#pragma once

#include "BehaviorState.h"
//#include "Graph.h"

class CowChasingState : public BehaviorState 
{
public:
	CowChasingState(std::shared_ptr<Cow> owner);
	~CowChasingState();

	void Move(std::shared_ptr<Graph> graph);
	void Update();
	void CheckState();

private:
	bool foundHare = false;
	//std::shared_ptr<Graph> graph;
};

