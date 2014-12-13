#include "CowChasingState.h"
#include "Controller.h"

CowChasingState::CowChasingState(std::shared_ptr<BaseUnit> owner) : BehaviorState(owner)
{
}


CowChasingState::~CowChasingState()
{
}

std::vector<std::shared_ptr<Vertex>> CowChasingState::Move()
{
	return std::vector<std::shared_ptr<Vertex>>();
}

void CowChasingState::Update(Controller* controller)
{
	
}

std::string CowChasingState::GetAction()
{
	return "chasing the hare";
}

void CowChasingState::CheckState()
{
}
