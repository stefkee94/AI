#include "HareWanderingState.h"
#include "Graph.h"
#include <iostream>

HareWanderingState::HareWanderingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareWanderingState::~HareWanderingState()
{
}

void HareWanderingState::Move(std::shared_ptr<Graph> graph)
{
	
	/*if (owner->GetVertex()->hasNewWeapon())
	{
		hasWeapon = true;
		owner->GetVertex()->setWeapon(false);
		std::vector<std::shared_ptr<Edge>> new_edges = owner->GetVertex()->GetEdges();
		std::vector<std::shared_ptr<Vertex>> new_positions = new_edges.at(Utils::RandomNumber(new_edges.size() - 1))->GetDestinations();
		new_positions[0]->setWeapon(true);
	}*/
}

void HareWanderingState::Update(std::shared_ptr<Graph> graph)
{
	std::shared_ptr<Vertex> current_vert = owner->GetVertex();
	std::vector<std::shared_ptr<Edge>> edges = current_vert->GetEdges();
	for (std::shared_ptr<Edge> edge : edges)
	{
		std::vector<std::shared_ptr<Vertex>> dests = edge->GetDestinations();
		for (std::shared_ptr<Vertex> vertex : dests)
		{
			if (vertex == graph->GetCowPosition())
			{
				// DO SOMETHING BECAUSE COW IS IN RANGE AND CHASING
				std::cout << "IN RANGE" << std::endl;
				CheckState();
				return;
			}
		}
	}
}

void HareWanderingState::CheckState()
{
	int number = rand() % 100;
	//if (number < 51)
		//owner->ChangeState(EnumState::HARE_FLEEING);
	//else if (number > 50 && number < 76)
		owner->ChangeState(EnumState::HARE_SEARCHING_WEAPON);
	//else
		//owner->ChangeState(EnumState::HARE_SEARCHING_SLEEPINGPILL);

	//owner->ChangeState(EnumState::HARE_FLEEING);
	/*if (hasWeapon)
		owner->ChangeState(EnumState::HARE_CHASING);*/
}
