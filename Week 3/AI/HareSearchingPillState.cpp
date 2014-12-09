#include "HareSearchingPillState.h"
#include "Graph.h"

HareSearchingPillState::HareSearchingPillState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}

std::vector<std::shared_ptr<Vertex>> HareSearchingPillState::Move(std::shared_ptr<Graph> graph)
{
	std::vector<std::shared_ptr<Vertex>> all_pos = graph->getPositions();
	std::shared_ptr<Vertex> current_pos = owner->GetVertex();
	for (std::shared_ptr<Vertex> pos : all_pos)
	{
		if (pos->hasNewPill())
		{
			if (owner->GetVertex() == pos)
			{
				pos->setPill(false);
				owner->SetPil(true);
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

void HareSearchingPillState::Update(std::shared_ptr<Graph> graph)
{
	/*std::vector<std::shared_ptr<Vertex>> all_pos = graph->getPositions();
	std::shared_ptr<Vertex> current_pos = owner->GetVertex();
	current_pos->setWeapon(false);
	all_pos[0]->setWeapon(true);*/
	CheckState();
}

std::string HareSearchingPillState::GetAction()
{
	return "searching for the sleeping pill";
}

void HareSearchingPillState::CheckState()
{
	owner->ChangeState(EnumState::HARE_WANDERING);
}

HareSearchingPillState::~HareSearchingPillState()
{
}
