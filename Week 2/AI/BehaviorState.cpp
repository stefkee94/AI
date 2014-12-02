#include "BehaviorState.h"

BehaviorState::BehaviorState(std::shared_ptr<BaseUnit> owner)
{
	this->owner = owner;
}


BehaviorState::~BehaviorState()
{
}


