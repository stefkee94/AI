#include "Cow.h"
#include "SteeringBehaviors.h"
#include "EnumState.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	state = new CowWanderingState(std::shared_ptr<MovingEntity>(this));

	Mass = 490;
	MaxForce = 20;
	MaxTurnRate = 40;
	points = 0;

	points_fleeing_hare = 0;
	points_fleeing_cow = 0;
	points_hiding_hare = 0;
	points_hiding_cow = 0;
	points_find_weapon_hare = 0;
	points_find_weapon_cow = 0;
	points_find_pill_hare = 0;
	points_find_pill_cow = 0;
}

Cow::~Cow()
{

}

void Cow::Reset()
{
	// Reset values
	Velocity = QVector2D(0, 0);
	Heading = QVector2D(0, 0);
	Side = QVector2D(0, 0);
	Mass = 100;
	MaxForce = 20;
	MaxTurnRate = 500;
	points = 0;

	pill = false;
	weapon = false;

	points_fleeing_hare = 0;
	points_fleeing_cow = 0;
	points_hiding_hare = 0;
	points_hiding_cow = 0;
	points_find_weapon_hare = 0;
	points_find_weapon_cow = 0;
	points_find_pill_hare = 0;
	points_find_pill_cow = 0;

	// Set state
	state = new CowWanderingState(std::shared_ptr<MovingEntity>(this));
}

void Cow::Respawn()
{
	// Reset values
	Velocity = QVector2D(0, 0);
	Heading = QVector2D(0, 0);
	Side = QVector2D(0, 0);
	Mass = 490;
	MaxForce = 20;
	MaxTurnRate = 40;
}

void Cow::Update(Controller* controller, double time_elapsed)
{
	state->Update(controller, time_elapsed);
	//GetStatePoints(controller);
}

int Cow::GetStatePoints(Controller* controller)
{
	int points = state->GetPoints(controller);

	switch (state->GetType())
	{
	case EnumState::COW_FIND_PILL:
		points_find_pill_hare += points;
		break;
	case EnumState::COW_FIND_WEAPON:
		points_find_weapon_hare += points;
		break;
	case EnumState::COW_FLEEING:
		points_fleeing_hare += points;
		break;
	case EnumState::COW_HIDING:
		if (HasPill())
			points_find_pill_cow += 1;
		break;
	}

	return points;
}

int Cow::Caught(Controller* controller)
{
	int points = state->GetPoints(controller);

	switch (state->GetType())
	{
	case EnumState::COW_FIND_PILL:
		points_find_pill_hare += points;
		break;
	case EnumState::COW_FIND_WEAPON:
		points_find_weapon_hare += points;
		break;
	case EnumState::COW_FLEEING:
		points_fleeing_hare += points;
		break;
	case EnumState::COW_HIDING:
		if (HasPill())
			points_find_pill_cow += 1;
		break;
	}

	return points;
}

int Cow::GetPointsFleeingHare()
{
	return points_fleeing_hare;
}

int Cow::GetPointsFleeingCow()
{
	return points_fleeing_cow;
}

int Cow::GetPointsHidingHare()
{
	return points_hiding_hare;
}

int Cow::GetPointsHidingCow()
{
	return points_hiding_cow;
}

int Cow::GetPointsFindWeaponHare()
{
	return points_find_weapon_hare;
}

int Cow::GetPointsFindWeaponCow()
{
	return points_find_weapon_cow;
}

int Cow::GetPointsFindPillHare()
{
	return points_find_pill_hare;
}

int Cow::GetPointsFindPillCow()
{
	return points_find_pill_cow;
}