#include "Cow.h"
#include "SteeringBehaviors.h"

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	state = new CowChasingState(std::shared_ptr<MovingEntity>(this));

	Mass = 490;
	MaxSpeed = 0.3;
	MaxForce = 20;
	MaxTurnRate = 40;
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

void Cow::Update(Controller* controller, double time_elapsed)
{
	state->Update(controller, time_elapsed);
}
