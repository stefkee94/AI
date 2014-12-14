#include "MovingEntity.h"

double MovingEntity::GetMass()
{
	return Mass;
}

double MovingEntity::GetMaxSpeed()
{
	return MaxSpeed;
}

double MovingEntity::GetMaxForce()
{
	return MaxForce;
}

double MovingEntity::GetMaxTurnRate()
{
	return MaxTurnRate;
}

QVector2D MovingEntity::GetVelocity()
{
	return Velocity;
}

QVector2D MovingEntity::GetHeading()
{
	return Heading;
}

QVector2D MovingEntity::GetSide()
{
	return Side;
}