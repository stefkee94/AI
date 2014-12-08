#include "HareWanderingState.h"
#include "Graph.h"
#include <iostream>

HareWanderingState::HareWanderingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareWanderingState::~HareWanderingState()
{
}


/*if (owner->GetVertex()->hasNewWeapon())
{
hasWeapon = true;
owner->GetVertex()->setWeapon(false);
std::vector<std::shared_ptr<Edge>> new_edges = owner->GetVertex()->GetEdges();
std::vector<std::shared_ptr<Vertex>> new_positions = new_edges.at(Utils::RandomNumber(new_edges.size() - 1))->GetDestinations();
new_positions[0]->setWeapon(true);
}*/
std::vector<std::shared_ptr<Vertex>> HareWanderingState::Move(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> route;
	std::shared_ptr<Vertex> next_pos;

	// Check if the cow is in range
	if (Utils::InRange(owner->GetVertex(), graph->GetCowPosition()))
	{
		CheckState();

	}
	else
	{
		std::vector<std::shared_ptr<Edge>> edges = owner->GetVertex()->GetEdges();
		std::vector<std::shared_ptr<Vertex>> positions = edges.at(Utils::RandomNumber(edges.size() - 1))->GetDestinations();
		
		// Get next vertex
		if (positions.at(0) != owner->GetVertex())
			next_pos = positions.at(0);
		else
			next_pos = positions.at(1);
	}

	route.push_back(next_pos);
	return route;
}

void HareWanderingState::Update(std::shared_ptr<Graph> graph)
{
	
}

std::string HareWanderingState::GetAction()
{
	return "wandering in the field";
}

void HareWanderingState::CheckState()
{
	int number = rand() % 100;
	if (number < 51)
	//	owner->ChangeState(EnumState::HARE_FLEEING);
	//else if (number > 50 && number < 76)
		owner->ChangeState(EnumState::HARE_SEARCHING_WEAPON);
	else
		owner->ChangeState(EnumState::HARE_SEARCHING_SLEEPINGPILL);

	//owner->ChangeState(EnumState::HARE_FLEEING);
	/*if (hasWeapon)
		owner->ChangeState(EnumState::HARE_CHASING);*/
}
