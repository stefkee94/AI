#pragma once

#include "MovingEntity.h"
#include "CowWanderingState.h"

class Cow : public MovingEntity, public std::enable_shared_from_this<Cow>
{
public:
	Cow();
	~Cow();

	void Reset();
	void Respawn();
	void Update(Controller* controller, double time_elapsed);
	int Caught(Controller* controller);
};

