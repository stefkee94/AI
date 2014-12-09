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
	if (owner->GetPil() && owner->GetVertex() == graph->GetCowPosition())
	{
		// Set the new position of the pill
		std::vector<std::shared_ptr<Vertex>> positions = graph->getPositions();
		positions.at(Utils::RandomNumber(positions.size() - 1))->setPill(true);

		

		std::vector<std::shared_ptr<Edge>> edges = owner->GetVertex()->GetEdges();
		std::vector<std::shared_ptr<Vertex>> new_positions = edges.at(Utils::RandomNumber(edges.size() - 1))->GetDestinations();

		// Get next vertex
		if (new_positions.at(0) != owner->GetVertex())
			next_pos = new_positions.at(0);
		else
			next_pos = new_positions.at(1);

		route.push_back(next_pos);
		
		// Change the current state of the hare
		CheckState();
	}
	else if (Utils::InRange(owner->GetVertex(), graph->GetCowPosition()))
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

		route.push_back(next_pos);
	}

	return route;
}

void HareWanderingState::Update(std::shared_ptr<Graph> graph)
{
	CheckState();
}

std::string HareWanderingState::GetAction()
{
	return "wandering in the field";
}

void HareWanderingState::CheckState()
{
	if (owner->GetPil())
	{
		owner->SetPil(false);
		owner->ChangeState(EnumState::HARE_FLEEING);
	}
	else
	{
		int number = rand() % 100;
		if (number < 51)
			owner->ChangeState(EnumState::HARE_SEARCHING_WEAPON);
		else
			owner->ChangeState(EnumState::HARE_SEARCHING_SLEEPINGPILL);
	}
}
