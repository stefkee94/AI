#pragma once

#include "BehaviorState.h"
class Vertex;
class CowChasingState : public BehaviorState 
{
public:
	CowChasingState(std::shared_ptr<BaseUnit> owner);
	~CowChasingState();

	void Move(std::shared_ptr<Graph> graph);
	void MoveCow(std::vector<std::shared_ptr<Vertex>> new_position);
	void Update();
	void CheckState();

private:
	bool foundHare = false;
	//std::shared_ptr<Graph> graph;
};
