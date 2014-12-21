#include "BehaviorState.h"

BehaviorState::BehaviorState(std::shared_ptr<MovingEntity> owner)
{
	this->owner = owner;
}


BehaviorState::~BehaviorState()
{
}


