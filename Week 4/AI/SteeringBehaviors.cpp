#include "SteeringBehaviors.h"
#include "MovingEntity.h"

SteeringBehaviors::SteeringBehaviors()
{
}


SteeringBehaviors::~SteeringBehaviors()
{
}

QVector2D SteeringBehaviors::Seek(QVector2D TargetPos, std::shared_ptr<MovingEntity> unit)
{
	TargetPos -= unit->GetPosition();
	QVector2D DesiredVelocity = TargetPos.normalized() * unit->GetMaxSpeed(); // TargetPos moet nog genormalized worden...

	return (DesiredVelocity - unit->GetVelocity());
}

QVector2D SteeringBehaviors::Flee(QVector2D TargetPos, std::shared_ptr<MovingEntity> unit)
{
	// Only flee if the target is within 'panic distance'. Work in distance squared space.
	const double PanicDistanceSq = 100 * 100;
	if (unit->GetPosition().distanceToPoint(TargetPos) > PanicDistanceSq)
	{
		return QVector2D();
	}

	TargetPos = unit->GetPosition() - TargetPos;
	QVector2D DesiredVelocity = TargetPos.normalized() * unit->GetMaxSpeed();

	return (DesiredVelocity - unit->GetVelocity());
}

QVector2D SteeringBehaviors::Arrive(QVector2D TargetPos, std::shared_ptr<MovingEntity> unit)
{
	QVector2D ToTarget = TargetPos - unit->GetPosition();

	// Calculate the distance to the target position
	double distance = ToTarget.length();

	if (distance > 0)
	{
		double DecelartionTweaker = 0.3;

		// Calculate the speed required to reach the target given the desired deceleration
		double speed = distance / (3 * DecelartionTweaker);

		// Make sure the velocity does not exceed the max
		if (speed > unit->GetMaxSpeed())
			speed = unit->GetMaxSpeed();

		QVector2D DesiredVelocity = ToTarget * speed / distance;
		return (DesiredVelocity - unit->GetVelocity());
	}

	return QVector2D();
}

QVector2D SteeringBehaviors::Pursuit(const std::shared_ptr<MovingEntity> target, std::shared_ptr<MovingEntity> unit)
{
	// If the target is ahead and facing the agent then we can just seek for the target's current position.
	QVector2D ToTarget = target->GetPosition() - unit->GetPosition();

	double RelativeHeading = unit->GetHeading().dotProduct(target->GetHeading(), unit->GetHeading());

	if ((ToTarget.dotProduct(unit->GetHeading(), target->GetHeading()) > 0) && (RelativeHeading < -0.95))
	{
		return Seek(target->GetPosition(), unit);
	}

	// Look ahead
	double LookAheadTime = ToTarget.length() / (unit->GetMaxSpeed() + target->GetMaxSpeed());

	// Seek the predicted future position of the target
	return Seek(target->GetPosition() + target->GetVelocity() * LookAheadTime, unit);
}

QVector2D SteeringBehaviors::Evade(const std::shared_ptr<MovingEntity> pursuer, std::shared_ptr<MovingEntity> unit)
{
	QVector2D ToPursuer = pursuer->GetPosition() - unit->GetPosition();

	// Look ahead
	double LookAheadTime = ToPursuer.length() / (unit->GetMaxSpeed() + pursuer->GetMaxSpeed());

	// Flee away from the predicted future position of the pursuer
	return Flee(pursuer->GetPosition() + pursuer->GetVelocity() * LookAheadTime, unit);
}

QVector2D SteeringBehaviors::Wander(std::shared_ptr<MovingEntity> unit)
{
	// First, add a small random vector to the target's position (RandomClamped returns a value between -1 and 1
	QVector2D target = QVector2D(Utils::RandomClamped() * WanderJitter, Utils::RandomClamped() * WanderJitter);

	// Reproject this new vector back onto a unit circle
	target.normalize();

	// Increase the length of the vector to the same as the radius of the wander circle
	target *= WanderRadius;

	// Move the target into a position WanderDist in front of the agen't
	QVector2D target_local = target + QVector2D(WanderDistance, 0);

	// Project the target into world space
	QVector2D target_world = PointToWorldSpace(target_local, unit->GetHeading(), unit->GetSide(), unit->GetPosition());

	return target_world;
}

QVector2D SteeringBehaviors::PointToWorldSpace(QVector2D target, QVector2D heading, QVector2D side, QVector2D position)
{
	//// Make a copy of the target
	//QVector2D point = target;

	//QMatrix matrix;

	////create a transformation matrix
	//C2DMatrix matTransform;

	////rotate
	//matTransform.Rotate(AgentHeading, AgentSide);

	////and translate
	//matTransform.Translate(AgentPosition.x, AgentPosition.y);

	////now transform the vertices
	//matTransform.TransformVector2Ds(TransPoint);

	//return TransPoint;

	return QVector2D();
}

QVector2D SteeringBehaviors::Calculate()
{
	return QVector2D();
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