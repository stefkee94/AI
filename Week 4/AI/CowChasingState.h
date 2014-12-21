#pragma once

#include <vector>

#include "Vertex.h"
#include "BehaviorState.h"

class Vertex;
class CowChasingState : public BehaviorState 
{
public:
	CowChasingState(std::shared_ptr<MovingEntity> owner);
	~CowChasingState();

	std::vector<std::shared_ptr<Vertex>> Move();
	void MoveCow(std::vector<std::shared_ptr<Vertex>> new_position);
	void CheckState();
	void Update(Controller* controller, double time_elapsed);
	std::string GetAction();

private:
	bool foundHare = false;
};

//'CowWanderingState::Move': overriding virtual function return type differs and is not covariant from 'BehaviorState::Move'