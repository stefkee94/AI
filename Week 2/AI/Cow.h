#pragma once

//#include "BehaviorState.h"
#include "BaseUnit.h"
#include "CowWanderingState.h"
#include "CowChasingState.h"

class Cow : public BaseUnit, public std::enable_shared_from_this<Cow>
{
public:
	Cow();
	~Cow();
	void Move(std::shared_ptr<Graph> graph);
	void Update();
	void ChangeState(EnumState new_state);
	EnumState GetState();
	QString GetImageLink();
	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	//BehaviorState* behavior;
	//EnumState currentState;
	//QString img_link;
	//std::shared_ptr<Vertex> vertex;
};

