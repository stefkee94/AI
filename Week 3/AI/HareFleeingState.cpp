#include "HareFleeingState.h"
#include "Graph.h"

HareFleeingState::HareFleeingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
	int counter = 5;
}

std::vector<std::shared_ptr<Vertex>> HareFleeingState::Move(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> route;

	// Check if the hare has fleed for 5 turns
	if (counter <= 0)
		CheckState();
	else
	{
		std::vector<std::shared_ptr<Edge>> edges;
		std::vector<std::shared_ptr<Vertex>> possible_positions_hare;
		std::vector<std::shared_ptr<Vertex>> possible_positions_cow;

		// Get all the possible positions of the hare
		edges = owner->GetVertex()->GetEdges();
		for (std::shared_ptr<Edge> edge : edges)
		{
			std::vector<std::shared_ptr<Vertex>> dests = edge->GetDestinations();
			for (std::shared_ptr<Vertex> vertex : dests)
			{
				if (vertex != owner->GetVertex())
					possible_positions_hare.push_back(vertex);
			}
		}

		// Get all the possible positions of the cow
		edges = graph->GetCowPosition()->GetEdges();
		for (std::shared_ptr<Edge> edge : edges)
		{
			std::vector<std::shared_ptr<Vertex>> dests = edge->GetDestinations();
			for (std::shared_ptr<Vertex> vertex : dests)
			{
				if (vertex != graph->GetCowPosition())
					possible_positions_cow.push_back(vertex);
			}
		}

		// Look for a position where the cow cant move to
		for (int x = 0; x < possible_positions_hare.size(); x++)
		{
			if (std::find(possible_positions_cow.begin(), possible_positions_cow.end(), possible_positions_hare.at(x)) == possible_positions_cow.end())
			{
				route.push_back(possible_positions_hare.at(x));
				break;
			}
		}

		// Drop counter by 1
		counter--;
	}
	
	return route;
}

void HareFleeingState::Update(std::shared_ptr<Graph> graph)
{

}

std::string HareFleeingState::GetAction()
{
	return "fleeing from the cow";
}

void HareFleeingState::CheckState()
{
	owner->ChangeState(EnumState::HARE_WANDERING);
}

HareFleeingState::~HareFleeingState()
{
}
