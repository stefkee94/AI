#include "Cow.h"
#include "SteeringBehaviors.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	state = new CowWanderingState(std::shared_ptr<MovingEntity>(this));

	Mass = 490;
	MaxForce = 20;
	MaxTurnRate = 40;
	points = 0;
}

Cow::~Cow()
{

}

void Cow::Reset()
{
	// Reset values
	Velocity = QVector2D(0, 0);
	Heading = QVector2D(0, 0);
	Side = QVector2D(0, 0);
	Mass = 100;
	MaxForce = 20;
	MaxTurnRate = 40;
	points = 0;

	// Set state
	state = new CowWanderingState(std::shared_ptr<MovingEntity>(this));
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
}

void Cow::Update(Controller* controller, double time_elapsed)
{
	state->Update(controller, time_elapsed);
	//GetStatePoints(controller);
}

int Cow::GetStatePoints(Controller* controller)
{
	return state->GetPoints(controller);
}

int Cow::Caught(Controller* controller)
{
	return state->GetPoints(controller);
}