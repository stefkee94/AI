#include "CowChasingState.h"
#include "Controller.h"

CowChasingState::CowChasingState(std::shared_ptr<MovingEntity> owner) : BehaviorState(owner)
{
}


CowChasingState::~CowChasingState()
{
}

std::vector<std::shared_ptr<Vertex>> CowChasingState::Move()
{
	return std::vector<std::shared_ptr<Vertex>>();
}

void CowChasingState::Update(Controller* controller, double time_elapsed)
{
	// Keep record of its current position
	QVector2D old_position = owner->GetPosition();

	// Calculate the combined force from each steering behavior
	QVector2D SteeringForce = owner->Pursuit(controller->GetHare());

	// Acceleration = Force / Mass
	QVector2D Acceleration = SteeringForce / owner->GetMass();

	// Update velocity
	QVector2D Velocity = owner->GetVelocity();
	Velocity += Acceleration * time_elapsed;

	// Make sure the unit does not exceed maximum velocity
	if (Velocity.length() > owner->GetMaxSpeed())
	{
		Velocity.normalize();
		Velocity *= owner->GetMaxSpeed();
	}

	// Update the position
	QVector2D Position = owner->GetPosition();
	Position += Velocity * time_elapsed;

	// Update the heading if the vehicle has a velocity greater than a very small value
	if (Velocity.lengthSquared() > 0.00000001)
	{
		QVector2D Heading = owner->GetHeading();
		Heading.normalize();
		owner->SetHeading(Heading);

		//Side = Heading.Perp(); --> Weet niet precies wat dit doet en zit niet in QT
	}

	// Set velocity and position
	owner->SetVelocity(Velocity);
	owner->SetPosition(Position);

	// Treat the screen as a toroid
	//WrapAround(Position, World->xClient(), Word->yClient());
}

std::string CowChasingState::GetAction()
{
	return "chasing the hare";
}

void CowChasingState::CheckState()
{
}
