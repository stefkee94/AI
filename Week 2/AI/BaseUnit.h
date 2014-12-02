#pragma once
#include <memory>
#include <qstring.h>
#include "Vertex.h"

#include "BehaviorState.h"
#include "EnumState.h"

class BaseUnit
{
public:
	virtual void Move() = 0;
	virtual void Update() = 0;
	virtual void ChangeState(EnumState state) = 0;
	virtual EnumState getState() = 0;
	virtual QString GetImageLink() = 0;
	virtual void SetVertex(std::shared_ptr<Vertex> p_vertex) = 0;
	virtual std::shared_ptr<Vertex> GetVertex() = 0;

protected:
	BehaviorState* behavior;
	EnumState currentState;
	std::shared_ptr<Vertex> vertex;
	QString img_link;
};

