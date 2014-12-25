#include "MovingEntity.h"
#include "Utils.h"

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

//////////////////////////////////////////////////
//												//
//				  Move Functions				//
//												//
//////////////////////////////////////////////////

QVector2D MovingEntity::Seek(QVector2D TargetPos)
{
	TargetPos -= GetPosition();
	QVector2D DesiredVelocity = TargetPos.normalized() * GetMaxSpeed();

	return (DesiredVelocity - GetVelocity());
}

QVector2D MovingEntity::Flee(QVector2D TargetPos)
{
	// Only flee if the target is within 'panic distance'. Work in distance squared space.
	const double PanicDistanceSq = 100 * 100;
	if (GetPosition().distanceToPoint(TargetPos) > PanicDistanceSq)
	{
		return QVector2D();
	}

	TargetPos = GetPosition() - TargetPos;
	QVector2D DesiredVelocity = TargetPos.normalized() * GetMaxSpeed();

	return (DesiredVelocity - GetVelocity());
}

QVector2D MovingEntity::Arrive(QVector2D TargetPos)
{
	QVector2D ToTarget = TargetPos - GetPosition();

	// Calculate the distance to the target position
	double distance = ToTarget.length();

	if (distance > 0)
	{
		double DecelartionTweaker = 0.3;

		// Calculate the speed required to reach the target given the desired deceleration
		double speed = distance / (3 * DecelartionTweaker);

		// Make sure the velocity does not exceed the max
		if (speed > GetMaxSpeed())
			speed = GetMaxSpeed();

		QVector2D DesiredVelocity = ToTarget * speed / distance;
		return (DesiredVelocity - GetVelocity());
	}

	return QVector2D();
}

QVector2D MovingEntity::Pursuit(const std::shared_ptr<MovingEntity> target)
{
	// If the target is ahead and facing the agent then we can just seek for the target's current position.
	QVector2D ToTarget = target->GetPosition() - GetPosition();

	double RelativeHeading = GetHeading().dotProduct(target->GetHeading(), GetHeading());

	if ((ToTarget.dotProduct(GetHeading(), target->GetHeading()) > 0) && (RelativeHeading < -0.95))
	{
		return Seek(target->GetPosition());
	}

	// Look ahead
	double LookAheadTime = ToTarget.length() / (GetMaxSpeed() + target->GetMaxSpeed());

	// Seek the predicted future position of the target
	return Seek(target->GetPosition() + target->GetVelocity() * LookAheadTime);
}

QVector2D MovingEntity::Evade(const std::shared_ptr<MovingEntity> pursuer)
{
	QVector2D ToPursuer = pursuer->GetPosition() - GetPosition();

	// Look ahead
	double LookAheadTime = ToPursuer.length() / (GetMaxSpeed() + pursuer->GetMaxSpeed());

	// Flee away from the predicted future position of the pursuer
	return Flee(pursuer->GetPosition() + pursuer->GetVelocity() * LookAheadTime);
}

QVector2D MovingEntity::Wander()
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
	QVector2D target_world = PointToWorldSpace(target_local, GetHeading(), GetSide(), GetPosition());

	return target_world;// -GetPosition();
}

QVector2D MovingEntity::PointToWorldSpace(QVector2D target, QVector2D heading, QVector2D side, QVector2D position)
{
	// Make a copy of the target
	QVector2D point = target;

	QMatrix matrix;

	//rotate
	//matrix.rotate(heading.x);// --> error, functie accepteert maar 1 param...
	//heading, side


	//and translate
	/*qreal x = position.x;
	qreal y = position.y;
	matrix.translate(x, y);*/

	//now transform the vertices
	// TODO --> transform point with matrix
	return point;


	//// Hieronder staat wat code uit het boek, commentaar is weggehaald, maar stappen zijn hetzelfde als hierboven.	
	////create a transformation matrix
	//C2DMatrix matTransform;

	//
	//matTransform.Rotate(AgentHeading, AgentSide);

	//
	//matTransform.Translate(AgentPosition.x, AgentPosition.y);

	//
	//matTransform.TransformVector2Ds(TransPoint);
}

//create a rotation matrix from a 2D vector
//inline void C2DMatrix::Rotate(const Vector2D &fwd, const Vector2D &side)
//{
//	C2DMatrix::Matrix mat;
//
//	mat._11 = fwd.x;  mat._12 = fwd.y; mat._13 = 0;
//
//	mat._21 = side.x; mat._22 = side.y; mat._23 = 0;
//
//	mat._31 = 0; mat._32 = 0; mat._33 = 1;
//
//	//and multiply
//	MatrixMultiply(mat);
//}

//applies a 2D transformation matrix to a single Vector2D
//inline void C2DMatrix::TransformVector2Ds(Vector2D &vPoint)
//{
//
//	double tempX = (m_Matrix._11*vPoint.x) + (m_Matrix._21*vPoint.y) + (m_Matrix._31);
//
//	double tempY = (m_Matrix._12*vPoint.x) + (m_Matrix._22*vPoint.y) + (m_Matrix._32);
//
//	vPoint.x = tempX;
//
//	vPoint.y = tempY;
//}