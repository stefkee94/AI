#pragma once
#include "BaseUnit.h"
class Hare : public BaseUnit, public std::enable_shared_from_this<Hare>
{

public:
	Hare();
	~Hare();
	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	QString GetImageLink();
	std::string GetAction();
	std::vector<std::shared_ptr<Vertex>> Move(std::shared_ptr<Graph> graph);
	void Update(Controller* controller, std::shared_ptr<Graph> graph);
	EnumState GetState();
	void SetPil(bool contains_pill);
	bool GetPil();
};

