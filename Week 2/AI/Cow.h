#pragma once

#include <memory>
#include <QString>
#include "Vertex.h"

#include "EnumState.h"
#include "CowWanderingState.h"
#include "CowChasingState.h"
#include "BehaviorState.h"

class Graph;
class Cow
{
private:
	std::shared_ptr<Vertex> vertex;
	QString img_link;
	// For the state
	BehaviorState* behavior;
	EnumState currentState;
	//std::shared_ptr<Graph> graph;
public:
	Cow();
	~Cow();

	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	QString GetImageLink();

	void Move(std::shared_ptr<Graph> graph);
	void Update();
	void ChangeState(EnumState new_state);
	EnumState GetState();
};

