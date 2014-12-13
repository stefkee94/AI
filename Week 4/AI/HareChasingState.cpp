#include "HareChasingState.h"
#include "Controller.h"
#include "Graph.h"

HareChasingState::HareChasingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareChasingState::~HareChasingState()
{
}

std::vector<std::shared_ptr<Vertex>> HareChasingState::Move(std::shared_ptr<Graph> graph)
{
	if (!shotCow)
	{
		std::shared_ptr<Vertex> hare_pos = owner->GetVertex();
		std::shared_ptr<Vertex> cow_pos = graph->GetCowPosition();
		return graph->GetRoute(hare_pos, cow_pos);
	}
	else
	{
		shotCow = false;
		CheckState();
		return std::vector<std::shared_ptr<Vertex>>();
	}
}

void HareChasingState::Update(Controller* controller, std::shared_ptr<Graph> graph)
{
	if (Utils::InRange(owner->GetVertex(), graph->GetCowPosition()))
	{
		// Set the new position of the weapon
		std::vector<std::shared_ptr<Vertex>> positions = graph->getPositions();
		positions.at(Utils::RandomNumber(positions.size() - 1))->setWeapon(true);

		// Shoot the cow and let it respawn
		std::cout << "The cow is shot" << std::endl;
		controller->RespawnCow();

		shotCow = true;
		// Change the state because the cow is shot
		//CheckState();
	}
}

std::string HareChasingState::GetAction()
{
	return "chasing the cow";
}

void HareChasingState::CheckState()
{
	owner->ChangeState(EnumState::HARE_WANDERING);
}