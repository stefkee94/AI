#pragma once

#include "MovingEntity.h"
#include "CowChasingState.h"

class Cow : public MovingEntity, public std::enable_shared_from_this<Cow>
{
public:
	Cow();
	~Cow();

	void Move(double time_elapsed);
	void Update(Controller* controller, double time_elapsed);
};

