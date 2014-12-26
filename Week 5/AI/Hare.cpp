#include "Hare.h"
#include <qdir.h>

Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");
	state = new HareChasingState(std::shared_ptr<MovingEntity>(this));

	Mass = 500;
	MaxForce = 20;
	MaxTurnRate = 40;
}

Hare::~Hare()
{
}

void Hare::Respawn()
{
	// Reset values
	Velocity = QVector2D(0, 0);
	Heading = QVector2D(0, 0);
	Side = QVector2D(0, 0);
	Mass = 500;
	MaxForce = 20;
	MaxTurnRate = 40;

	// Reset state
	state = new HareChasingState(std::shared_ptr<MovingEntity>(this));
}

void Hare::Update(Controller* controller, double time_elapsed)
{
	state->Update(controller, time_elapsed);
}
