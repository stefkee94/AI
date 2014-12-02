#include "BehaviorState.h"

BehaviorState::BehaviorState(std::shared_ptr<Cow> owner)
{
	this->owner = owner;
}


BehaviorState::~BehaviorState()
{
}


