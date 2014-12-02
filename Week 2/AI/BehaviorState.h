#pragma once
#include <memory>

class Graph;
class Cow;
class BehaviorState
{
public:
	BehaviorState(std::shared_ptr<Cow> owner);
	virtual ~BehaviorState();

	virtual void Move(std::shared_ptr<Graph> graph) = 0;
	virtual void Update() = 0;
	virtual void CheckState() = 0;

protected:
	// The owner in this case is only the cow
	std::shared_ptr<Cow> owner;
	
};

