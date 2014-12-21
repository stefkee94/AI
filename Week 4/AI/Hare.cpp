#include "Hare.h"
#include <qdir.h>

Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");
	state = new HareWanderingState(std::shared_ptr<MovingEntity>(this));

	Mass = 100;
	MaxSpeed = 0.4;
	MaxForce = 20;
	MaxTurnRate = 40;
}

Hare::~Hare()
{
}

void Hare::Move(double time_elapsed)
{
	// Send behavior to state
	//return state->Move();
}

void Hare::Update(Controller* controller, double time_elapsed)
{
	state->Update(controller, time_elapsed);
}
