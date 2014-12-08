#pragma once

#include <memory>
#include <vector>

class Vertex;
class BaseUnit;
class Graph;
class BehaviorState
{
public:
	BehaviorState(std::shared_ptr<BaseUnit> owner);
	virtual ~BehaviorState();

	virtual std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph) = 0;
	virtual void CheckState() = 0;
	virtual void Update(std::shared_ptr<Graph> graph) = 0;

protected:
	std::shared_ptr<BaseUnit> owner;
	
};
