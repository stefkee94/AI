#include "BaseUnit.h"
#include "CowChasingState.h"
#include "CowWanderingState.h"
#include "HareWanderingState.h"
#include "HareChasingState.h"

void BaseUnit::ChangeState(EnumState new_state)
{
	switch (new_state)
	{
		case EnumState::COW_WANDERING:
			behavior = new CowWanderingState(std::shared_ptr<BaseUnit>(this));
			break;
		case EnumState::COW_CHASING:
			behavior = new CowChasingState(std::shared_ptr<BaseUnit>(this));
			break;
		case EnumState::HARE_WANDERING:
			behavior = new HareWanderingState(std::shared_ptr<BaseUnit>(this));
			break;
		case EnumState::HARE_CHASING:
			behavior = new HareChasingState(std::shared_ptr<BaseUnit>(this));
	}
	currentState = new_state;
}
