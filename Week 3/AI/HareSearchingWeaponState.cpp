#include "HareSearchingWeaponState.h"
#include "Graph.h"

HareSearchingWeaponState::HareSearchingWeaponState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}

std::vector<std::shared_ptr<Vertex>> HareSearchingWeaponState::Move(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> all_pos = graph->getPositions();
	std::shared_ptr<Vertex> current_pos = owner->GetVertex();
	for (std::shared_ptr<Vertex> pos : all_pos)
	{
		if (pos->hasNewWeapon())
		{
			if (owner->GetVertex() == pos)
			{
				pos->setWeapon(false);
				CheckState();
				break;
			}
			else
			{
				return graph->GetRoute(owner->GetVertex(), pos);
			}
		}
	}

	return std::vector<std::shared_ptr<Vertex>>();
}

void HareSearchingWeaponState::Update(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> all_pos = graph->getPositions();
	std::shared_ptr<Vertex> current_pos = owner->GetVertex();
	current_pos->setWeapon(false);
	all_pos[0]->setWeapon(true);
}

std::string HareSearchingWeaponState::GetAction()
{
	return "searching for the weapon";
}

void HareSearchingWeaponState::CheckState()
{
	owner->ChangeState(EnumState::HARE_CHASING);
}

HareSearchingWeaponState::~HareSearchingWeaponState()
{
}
