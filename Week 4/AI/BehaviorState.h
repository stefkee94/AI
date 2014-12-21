#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <qvector2d.h>

class Controller;
class Vertex;
class MovingEntity;
class Graph;
class BehaviorState
{
public:
	BehaviorState(std::shared_ptr<MovingEntity> owner);
	virtual ~BehaviorState();

	virtual std::vector<std::shared_ptr<Vertex>> Move() = 0;
	virtual void CheckState() = 0;
	virtual void Update(Controller* controller, double time_elapsed) = 0;
	virtual std::string GetAction() = 0;

protected:
	std::shared_ptr<MovingEntity> owner;
	
};

