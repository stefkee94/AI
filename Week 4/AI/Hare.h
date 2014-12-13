#pragma once

#include "BaseUnit.h"
#include "HareWanderingState.h"

class Hare : public BaseUnit, public std::enable_shared_from_this<Hare>
{

public:
	Hare();
	~Hare();
	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	QString GetImageLink();
	std::string GetAction();
	std::vector<std::shared_ptr<Vertex>> Move();
	void Update(Controller* controller);
	EnumState GetState();
	void SetPil(bool contains_pill);
	bool GetPil();
};

