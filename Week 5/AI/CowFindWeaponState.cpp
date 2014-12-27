#include "CowFindWeaponState.h"
#include "Controller.h"
#include "Utils.h"

CowFindWeaponState::CowFindWeaponState(std::shared_ptr<MovingEntity> owner) : BehaviorState(owner)
{
	owner->SetMaxSpeed(0.5);
}


CowFindWeaponState::~CowFindWeaponState()
{
}

void CowFindWeaponState::Update(Controller* controller, double time_elapsed)
{
	// Keep record of its current position
	QVector2D old_position = owner->GetPosition();

	// Calculate the combined force from each steering behavior
	QVector2D SteeringForce = owner->Find(controller->GetWeapon());

	// Acceleration = Force / Mass
	QVector2D Acceleration = SteeringForce / owner->GetMass();

	// Update velocity
	QVector2D Velocity = owner->GetVelocity();
	Velocity += Acceleration * time_elapsed;

	// Make sure the unit does not exceed maximum velocity
	float length = Velocity.length();
	if (Velocity.length() > owner->GetMaxSpeed())
	{
		Velocity.normalized();
		Velocity *= owner->GetMaxSpeed();
	}

	// Update the position
	QVector2D Position = owner->GetPosition();
	Position += Velocity;

	// Update the heading if the vehicle has a velocity greater than a very small value
	if (Velocity.lengthSquared() > 0.00000001)
	{
		QVector2D Heading = owner->GetHeading();
		Heading.normalized();
		owner->SetHeading(Heading);

		//Side = Heading.Perp(); --> Weet niet precies wat dit doet en zit niet in QT
	}

	// Treat the screen as a toroid
	double max_x = controller->GetWidth();
	double max_y = controller->GetHeight();

	if (Position.x() > max_x)
		Position.setX(0);
	if (Position.x() < 0)
		Position.setX(max_x);
	if (Position.y() > max_y)
		Position.setY(0);
	if (Position.y() < 0)
		Position.setY(max_y);

	// Set velocity and position
	owner->SetVelocity(Velocity);
	owner->SetPosition(Position);

	// Check if the owner can get the pill
	if ((owner->GetPosition() - controller->GetWeapon()->GetPosition()).length() < 2)
	{
		owner->SetWeapon(true);
		controller->RespawnWeapon();
		owner->SetState(new CowHideState(owner));
	}
}

std::string CowFindWeaponState::GetAction()
{
	return "looking for a weapon";
}

void CowFindWeaponState::CheckState()
{
}

int CowFindWeaponState::GetPoints(Controller* controller)
{
	if (!owner->HasWeapon())
	{
		controller->RespawnHare();
		controller->RespawnCow();
		owner->SetState(new CowWanderingState(owner));
		return 10;
	}
}