#pragma once

#include <QVector2D>
#include <QMatrix>
#include <memory>

#include "BaseUnit.h"

class Utils;
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

	virtual QVector2D Seek(QVector2D TargetPos);
	virtual QVector2D Flee(QVector2D TargetPos);
	virtual QVector2D Arrive(QVector2D TargetPos);
	virtual QVector2D Pursuit(const std::shared_ptr<MovingEntity> target);
	virtual QVector2D Evade(const std::shared_ptr<MovingEntity> pursuer);
	virtual QVector2D Wander();
	virtual QVector2D PointToWorldSpace(QVector2D target, QVector2D heading, QVector2D side, QVector2D position);

protected:
	// Variables
	QVector2D Velocity;
	QVector2D Heading;
	QVector2D Side;

	double Mass;
	double MaxSpeed;
	double MaxForce;
	double MaxTurnRate;

	double WanderRadius = 1.2;
	double WanderDistance = 2.0;
	double WanderJitter = 80.0;
};

