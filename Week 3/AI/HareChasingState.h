#pragma once

#include <vector>
#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class HareChasingState : public BehaviorState
{
public:
	HareChasingState(std::shared_ptr<BaseUnit> owner);
	virtual ~HareChasingState();

	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void CheckState();
	void Update(std::shared_ptr<Graph> graph);
	std::string GetAction();

private:
	bool shotCow = false;
};

