#pragma once

#include "MovingEntity.h"
#include "HareChasingState.h"

class Hare : public MovingEntity, public std::enable_shared_from_this<Hare>
{
public:
	Hare();
	~Hare();

	void Reset();
	void Respawn();
	void Update(Controller* controller, double time_elapsed);
};

