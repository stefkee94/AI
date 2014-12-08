#include "BaseUnit.h"
#include "CowChasingState.h"
#include "CowWanderingState.h"
#include "HareWanderingState.h"
#include "HareChasingState.h"
#include "HareFleeingState.h"
#include "HareSearchingWeaponState.h"
#include "HareSearchingPillState.h"

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
		break;
	case EnumState::HARE_FLEEING:
		behavior = new HareFleeingState(std::shared_ptr<BaseUnit>(this));
		break;
	case EnumState::HARE_SEARCHING_WEAPON:
		behavior = new HareSearchingWeaponState(std::shared_ptr<BaseUnit>(this));
		break;
	case EnumState::HARE_SEARCHING_SLEEPINGPILL:
		behavior = new HareSearchingPillState(std::shared_ptr<BaseUnit>(this));
		break;
	}
	currentState = new_state;
}
