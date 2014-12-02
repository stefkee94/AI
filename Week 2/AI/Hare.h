#pragma once

#include "BaseUnit.h"
#include "HareWanderingState.h"

class Hare : public BaseUnit, public std::enable_shared_from_this<BaseUnit>
{

public:
	Hare();
	~Hare();

	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	QString GetImageLink();

	void Move(std::shared_ptr<Graph> graph);
	void Update();
	void ChangeState(EnumState new_state);
	EnumState GetState();
};

