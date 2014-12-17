#include "MovingEntity.h"

void MovingEntity::Move(double time_elapsed)
{}
void MovingEntity::Update(double time_elapsed)
{}

//////////////////////////////////////////////////
//												//
//					Getters						//
//												//
//////////////////////////////////////////////////
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

//////////////////////////////////////////////////
//												//
//					Setters						//
//												//
//////////////////////////////////////////////////

void MovingEntity::SetMass(double Mass)
{
	this->Mass = Mass;
}

void MovingEntity::SetMaxSpeed(double MaxSpeed)
{
	this->MaxSpeed = MaxSpeed;
}

void MovingEntity::SetMaxForce(double MaxForce)
{
	this->MaxForce = MaxForce;
}

void MovingEntity::SetMaxTurnRate(double MaxTurnRate)
{
	this->MaxTurnRate = MaxTurnRate;
}

void MovingEntity::SetVelocity(QVector2D Velocity)
{
	this->Velocity = Velocity;
}

void MovingEntity::SetHeading(QVector2D Heading)
{
	this->Heading = Heading;
}

void MovingEntity::SetSide(QVector2D Side)
{
	this->Side = Side;
}