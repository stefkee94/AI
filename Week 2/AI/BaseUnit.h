#pragma once
#include <memory>
#include <qstring.h>
#include "EnumState.h"
#include "BehaviorState.h"
class Vertex;
class Graph;
class Cow;
class Hare;
class BaseUnit
{
public:
	virtual void Move(std::shared_ptr<Graph> graph) = 0;
	void ChangeState(EnumState state);
	virtual EnumState GetState() = 0;
	virtual QString GetImageLink() = 0;
	virtual void SetVertex(std::shared_ptr<Vertex> p_vertex) = 0;
	virtual std::shared_ptr<Vertex> GetVertex() = 0;

protected:
	BehaviorState* behavior;
	EnumState currentState;
	std::shared_ptr<Vertex> vertex;
	QString img_link;
};

