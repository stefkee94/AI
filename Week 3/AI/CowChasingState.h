#pragma once
#include <vector>
#include "BehaviorState.h"
class Vertex;
class CowChasingState : public BehaviorState 
{
public:
	CowChasingState(std::shared_ptr<BaseUnit> owner);
	~CowChasingState();

	void Move(std::shared_ptr<Graph> graph);
	void MoveCow(std::vector<std::shared_ptr<Vertex>> new_position);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);

private:
	bool foundHare = false;
};

