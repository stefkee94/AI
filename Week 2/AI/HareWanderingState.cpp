#include "HareWanderingState.h"
#include "Graph.h"
HareWanderingState::HareWanderingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


HareWanderingState::~HareWanderingState()
{
}

void HareWanderingState::Move(std::shared_ptr<Graph> graph)
{
	// DO NOTHING
	if (owner->GetVertex()->hasNewWeapon())
	{
		hasWeapon = true;
		owner->GetVertex()->setWeapon(false);
		std::vector<std::shared_ptr<Edge>> new_edges = owner->GetVertex()->GetEdges();
		std::vector<std::shared_ptr<Vertex>> new_positions = new_edges.at(Utils::RandomNumber(new_edges.size() - 1))->GetDestinations();
		new_positions[0]->setWeapon(true);
	}
		
}

void HareWanderingState::Update()
{

}

void HareWanderingState::CheckState()
{
	if (hasWeapon)
		owner->ChangeState(EnumState::HARE_CHASING);
}
