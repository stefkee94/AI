#include "SteeringBehaviors.h"
#include "MovingEntity.h"

SteeringBehaviors::SteeringBehaviors()
{
}


SteeringBehaviors::~SteeringBehaviors()
{
}

QVector2D SteeringBehaviors::Calculate()
{
	return QVector2D(100, -2);
}

QVector2D SteeringBehaviors::ForwardComponent()
{
	return QVector2D();
}

QVector2D SteeringBehaviors::SideComponent()
{
	return QVector2D();
}

void SteeringBehaviors::SetPath()
{

}

void SteeringBehaviors::SetTarget(QVector2D target)
{

}


void SteeringBehaviors::SeekOn()
{

}

void SteeringBehaviors::FleeOn()
{

}

void SteeringBehaviors::ArriveOn()
{

}

void SteeringBehaviors::WanderOn(std::shared_ptr<MovingEntity> unit)
{

}

void SteeringBehaviors::PursuitOn(const std::shared_ptr<MovingEntity> target, std::shared_ptr<MovingEntity> unit)
{

}

void SteeringBehaviors::SeekOff()
{

}

void SteeringBehaviors::FleeOff()
{

}

void SteeringBehaviors::ArriveOff()
{

}