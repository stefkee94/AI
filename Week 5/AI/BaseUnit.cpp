#include "BaseUnit.h"

QString BaseUnit::GetImageLink()
{
	return img_link;
}

std::string BaseUnit::GetAction()
{
	return state->GetAction();
}

EnumState BaseUnit::GetEnumState()
{
	return currentEnumState;
}

QVector2D BaseUnit::GetPosition()
{
	return Position;
}

bool BaseUnit::HasPill()
{
	return pill;
}

bool BaseUnit::HasWeapon()
{
	return weapon;
}

int BaseUnit::GetPoints()
{
	return points;
}

void BaseUnit::SetPosition(QVector2D position)
{
	this->Position = position;
}

void BaseUnit::SetState(BehaviorState* state)
{
	this->state = state;
}

void BaseUnit::SetPoints(int points)
{
	this->points = points;
}

void BaseUnit::AddPoints(int points)
{
	this->points += points;
}