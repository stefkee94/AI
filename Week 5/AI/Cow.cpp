#include "Cow.h"
#include "SteeringBehaviors.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	state = new CowWanderingState(std::shared_ptr<MovingEntity>(this));

	Mass = 490;
	MaxForce = 20;
	MaxTurnRate = 40;
}

Cow::~Cow()
{

}

void Cow::Respawn()
{
	// Reset values
	Velocity = QVector2D(0, 0);
	Heading = QVector2D(0, 0);
	Side = QVector2D(0, 0);
	Mass = 490;
	MaxForce = 20;
	MaxTurnRate = 40;

	// Reset State
	state = new CowWanderingState(std::shared_ptr<MovingEntity>(this));
}

void Cow::Update(Controller* controller, double time_elapsed)
{
	state->Update(controller, time_elapsed);
}

int Cow::Caught(Controller* controller)
{
	return state->GetPoints(controller);
}