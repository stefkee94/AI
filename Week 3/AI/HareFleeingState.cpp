#include "HareFleeingState.h"
#include "Graph.h"

HareFleeingState::HareFleeingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}

std::vector<std::shared_ptr<Vertex>> HareFleeingState::Move(std::shared_ptr<Graph> graph)
{
	//std::shared_ptr<Vertex> current_vert = owner->GetVertex();
	//std::vector<std::shared_ptr<Edge>> edges = current_vert->GetEdges();
	//for (std::shared_ptr<Edge> edge : edges)
	//{
	//	std::vector<std::shared_ptr<Vertex>> dests = edge->GetDestinations();
	//	for (std::shared_ptr<Vertex> vertex : dests)
	//	{
	//		if (vertex != graph->GetCowPosition())
	//		{
	//			// After set one place further, change state (because of small graph)
	//			owner->SetVertex(vertex);
	//			CheckState();
	//			return;
	//		}
	//	}
	//}

	return std::vector<std::shared_ptr<Vertex>>();
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
