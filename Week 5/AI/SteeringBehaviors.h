#pragma once

#include <QVector2D>
#include <QMatrix>
#include <memory>


#include "Utils.h"

class MovingEntity;
class SteeringBehaviors
{
private:
	double WanderRadius;
	double WanderDistance;
	double WanderJitter;

public:
	SteeringBehaviors();
	~SteeringBehaviors();

	QVector2D Seek(QVector2D TargetPos, std::shared_ptr<MovingEntity> unit);
	QVector2D Flee(QVector2D TargetPos, std::shared_ptr<MovingEntity> unit);
	QVector2D Arrive(QVector2D TargetPos, std::shared_ptr<MovingEntity> unit);
	QVector2D Pursuit(const std::shared_ptr<MovingEntity> target, std::shared_ptr<MovingEntity> unit);
	QVector2D Evade(const std::shared_ptr<MovingEntity> pursuer, std::shared_ptr<MovingEntity> unit);

	QVector2D Wander(std::shared_ptr<MovingEntity> unit);
	QVector2D PointToWorldSpace(QVector2D target, QVector2D heading, QVector2D side, QVector2D position);
	QVector2D Calculate();
	QVector2D ForwardComponent();
	QVector2D SideComponent();

	void SetPath();
	void SetTarget(QVector2D);

	void SeekOn();
	void FleeOn();
	void ArriveOn();
	void WanderOn(std::shared_ptr<MovingEntity> unit);
	void PursuitOn(const std::shared_ptr<MovingEntity> target, std::shared_ptr<MovingEntity> unit);;

	void SeekOff();
	void FleeOff();
	void ArriveOff();
};

