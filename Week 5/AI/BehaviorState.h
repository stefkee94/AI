#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <qvector2d.h>

class Utils;
class Controller;
class MovingEntity;
class BehaviorState
{
public:
	BehaviorState(std::shared_ptr<MovingEntity> owner);
	virtual ~BehaviorState();

	virtual void CheckState() = 0;
	virtual void Update(Controller* controller, double time_elapsed) = 0;
	virtual std::string GetAction() = 0;
	virtual int GetPoints(Controller* controller) = 0;

protected:
	std::shared_ptr<MovingEntity> owner;
	
};

