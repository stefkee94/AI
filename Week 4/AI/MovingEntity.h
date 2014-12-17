#pragma once

#include <QVector2D>
#include "BaseUnit.h"

class SteeringBehaviors;
class MovingEntity : public BaseUnit
{
public:
	virtual void Move(double time_elapsed);
	virtual void Update(double time_elapsed);

	virtual double GetMass();
	virtual double GetMaxSpeed();
	virtual double GetMaxForce();
	virtual double GetMaxTurnRate();

	virtual QVector2D GetVelocity();
	virtual QVector2D GetHeading();
	virtual QVector2D GetSide();

	virtual void SetMass(double Mass);
	virtual void SetMaxSpeed(double MaxSpeed);
	virtual void SetMaxForce(double MaxForce);
	virtual void SetMaxTurnRate(double MaxTurnRate);

	virtual void SetVelocity(QVector2D Velocity);
	virtual void SetHeading(QVector2D Heading);
	virtual void SetSide(QVector2D Side);

protected:
	QVector2D Velocity;
	QVector2D Heading;
	QVector2D Side;

	double Mass = 10;
	double MaxSpeed = 50;
	double MaxForce = 20;
	double MaxTurnRate = 40;

	SteeringBehaviors* Steering;
};

