#pragma once

#include <QVector2D>
#include "BaseUnit.h"
#include "SteeringBehaviors.h"

class SteeringBehaviors;
class MovingEntity : public BaseUnit
{
public:
	virtual void Move(double time_elapsed) = 0;
	virtual void Update(double time_elapsed) = 0;

	virtual double GetMass();
	virtual double GetMaxSpeed();
	virtual double GetMaxForce();
	virtual double GetMaxTurnRate();

	virtual QVector2D GetVelocity();
	virtual QVector2D GetHeading();
	virtual QVector2D GetSide();

protected:
	QVector2D Velocity;
	QVector2D Heading;
	QVector2D Side;

	double Mass = 10;
	double MaxSpeed = 50;
	double MaxForce = 20;
	double MaxTurnRate = 40;
};

