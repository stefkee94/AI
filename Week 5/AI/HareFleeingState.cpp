#include "HareFleeingState.h"
#include "Graph.h"

HareFleeingState::HareFleeingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner), counter(2)
{
}

std::vector<std::shared_ptr<Vertex>> HareFleeingState::Move(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> route;
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
		if (owner->GetVertex() == graph->GetCowPosition())
		{
			route.push_back(possible_positions_hare.at(0));
			break;
		}

		if (std::find(possible_positions_cow.begin(), possible_positions_cow.end(), possible_positions_hare.at(x)) == possible_positions_cow.end())
		{
			if (possible_positions_hare.at(x) != graph->GetCowPosition())
			{
				route.push_back(possible_positions_hare.at(x));
				break;
			}
		}
	}
	
	return route;
}

void HareFleeingState::Update(Controller* controller, std::shared_ptr<Graph> graph)
{
	if (counter <= 0)
		CheckState();
	else
		counter--;
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
