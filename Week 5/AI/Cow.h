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
	int GetStatePoints(Controller* controller);

	int GetPointsFleeingHare();
	int GetPointsFleeingCow();
	int GetPointsHidingHare();
	int GetPointsHidingCow();
	int GetPointsFindWeaponHare();
	int GetPointsFindWeaponCow();
	int GetPointsFindPillHare();
	int GetPointsFindPillCow();

private:
	int points_fleeing_hare;
	int points_fleeing_cow;
	int points_hiding_hare;
	int points_hiding_cow;
	int points_find_weapon_hare;
	int points_find_weapon_cow;
	int points_find_pill_hare;
	int points_find_pill_cow;
};

