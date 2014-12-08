#include "HareChasingState.h"
#include "Graph.h"

HareChasingState::HareChasingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareChasingState::~HareChasingState()
{
}

std::vector<std::shared_ptr<Vertex>> HareChasingState::Move(std::shared_ptr<Graph> graph)
{
	// in chasing mode, move the cow to other place and change state to wandering
	if (Utils::InRange(owner->GetVertex(), graph->GetCowPosition()))
	{
		// Set the new position of the weapon
		std::vector<std::shared_ptr<Vertex>> positions = graph->getPositions();
		positions.at(Utils::RandomNumber(positions.size() - 1))->setWeapon(true);

		// Change the state because the cow is shot
		shotCow = true;		
		CheckState();

		// Return an empty route
		return std::vector<std::shared_ptr<Vertex>>();
	}
	else
	{
		std::shared_ptr<Vertex> hare_pos = owner->GetVertex();
		std::shared_ptr<Vertex> cow_pos = graph->GetCowPosition();
		return graph->GetRoute(hare_pos, cow_pos);
	}
}

void HareChasingState::Update(std::shared_ptr<Graph> graph)
{

}

void HareChasingState::CheckState()
{
	if (shotCow)
		owner->ChangeState(EnumState::HARE_WANDERING);
}
