#include "Cow.h"
#include "SteeringBehaviors.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	state = new CowChasingState(std::shared_ptr<BaseUnit>(this));
}

Cow::~Cow()
{

}

void Cow::Move(double time_elapsed)
{
	// Send behavior to state
	//behavior->CheckState();
	//return behavior->Move();
}

void Cow::Update(double time_elapsed)
{
	// Keep record of its current position
	QVector2D old_position = GetPosition();

	// Calculate the combined force from each steering behavior
	QVector2D SteeringForce = Steering->Calculate();

	// Acceleration = Force / Mass
	QVector2D Acceleration = SteeringForce / Mass;

	// Update velocity
	Velocity += Acceleration * time_elapsed;
	
	// Make sure the unit does not exceed maximum velocity
	if (Velocity.length() > MaxSpeed)
	{
		Velocity.normalize();
		Velocity *= MaxSpeed;
	}

	// Update the position
	Position += Velocity * time_elapsed;

	// Update the heading if the vehicle has a velocity greater than a very small value
	if (Velocity.lengthSquared() > 0.00000001)
	{
		Heading.normalize();
		//Side = Heading.Perp(); --> Weet niet precies wat dit doet en zit niet in QT
	}

	// Treat the screen as a toroid
	//WrapAround(Position, World->xClient(), Word->yClient());
}
