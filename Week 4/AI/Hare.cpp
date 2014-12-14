#include "Hare.h"
#include <qdir.h>

Hare::Hare()
{
	img_link = QDir::currentPath().append("/Resources/rabbit-3.png");
	state = new HareWanderingState(std::shared_ptr<BaseUnit>(this));
}

Hare::~Hare()
{
}

void Hare::Move(double time_elapsed)
{
	// Send behavior to state
	//return state->Move();
}

void Hare::Update(double time_elapsed)
{
	//state->Update(controller);
}
