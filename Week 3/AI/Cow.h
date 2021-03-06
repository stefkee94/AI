#pragma once

#include "BaseUnit.h"
#include "CowWanderingState.h"
#include "CowChasingState.h"

class Cow : public BaseUnit, public std::enable_shared_from_this<Cow>
{
public:
	Cow();
	~Cow();
	std::vector<std::shared_ptr<Vertex>>  Move(std::shared_ptr<Graph> graph);
	void Update(Controller* controller, std::shared_ptr<Graph> graph);
	EnumState GetState();
	QString GetImageLink();
	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	std::string GetAction();
	void SetPil(bool contains_pill);
	bool GetPil();
};

