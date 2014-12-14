#pragma once

#include "MovingEntity.h"
#include "HareWanderingState.h"

class Hare : public MovingEntity, public std::enable_shared_from_this<Hare>
{

public:
	Hare();
	~Hare();

	void Move(double time_elapsed);
	void Update(double time_elapsed);
};

