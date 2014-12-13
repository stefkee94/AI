#pragma once

#include <iostream>
#include <memory>
#include <vector>

class Controller;
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
	virtual void Update(Controller* controller, std::shared_ptr<Graph> graph) = 0;
	virtual std::string GetAction() = 0;

protected:
	std::shared_ptr<BaseUnit> owner;
	
};

