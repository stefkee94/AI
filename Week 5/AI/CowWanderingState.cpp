#include "CowWanderingState.h"
#include "Graph.h"
//#include "BaseUnit.h"

CowWanderingState::CowWanderingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
	//this->owner = owner;
	//this->current_vertex = current_vertex;
}


CowWanderingState::~CowWanderingState()
{
}

//Logic for moving cow in the wandering state
std::vector<std::shared_ptr<Vertex>> CowWanderingState::Move(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> route;

	// Always get first item to walk
	std::vector<std::shared_ptr<Edge>> edges = owner->GetVertex()->GetEdges();
	std::vector<std::shared_ptr<Vertex>> positions = edges.at(Utils::RandomNumber(edges.size() - 1))->GetDestinations();
	std::shared_ptr<Vertex> next_pos;

	// Get next vertex
	if (positions.at(0) != owner->GetVertex())
		next_pos = positions.at(0);
	else
		next_pos = positions.at(1);

	route.push_back(next_pos);

	// Get route from owner vertex to next position
	//owner->SetVertex(next_pos);
	if (next_pos->hasNewPill())
	{
		hasEatenPill = true;
		next_pos->setPill(false);
		std::vector<std::shared_ptr<Edge>> new_edges = next_pos->GetEdges();
		std::vector<std::shared_ptr<Vertex>> new_positions = edges.at(Utils::RandomNumber(edges.size() - 1))->GetDestinations();
		new_positions[0]->setPill(true);
	}	

	return route;
}

void CowWanderingState::Update(Controller* controller, std::shared_ptr<Graph> graph)
{

}

std::string CowWanderingState::GetAction()
{
	return "wandering in the field";
}

void CowWanderingState::CheckState()
{
	//TODO : IF PILL FOUND CHANGE STATE
	if (hasEatenPill)
	{
		hasEatenPill = false;
		owner->ChangeState(EnumState::COW_CHASING);
	}
}
