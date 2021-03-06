#pragma once
#include <memory>
class BaseUnit;
class Graph;
class BehaviorState
{
public:
	BehaviorState(std::shared_ptr<BaseUnit> owner);
	virtual ~BehaviorState();

	virtual void Move(std::shared_ptr<Graph> graph) = 0;
	virtual void CheckState() = 0;

protected:
	std::shared_ptr<BaseUnit> owner;
	
};

