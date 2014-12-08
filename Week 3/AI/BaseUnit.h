#pragma once

#include <vector>
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
	virtual std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph) = 0;
	void ChangeState(EnumState state);
	virtual void Update(std::shared_ptr<Graph> graph) = 0;
	virtual EnumState GetState() = 0;
	virtual QString GetImageLink() = 0;
	virtual void SetVertex(std::shared_ptr<Vertex> p_vertex) = 0;
	virtual std::shared_ptr<Vertex> GetVertex() = 0;
	virtual std::string GetAction() = 0;

protected:
	BehaviorState* behavior;
	EnumState currentState;
	std::shared_ptr<Vertex> vertex;
	QString img_link;
};

