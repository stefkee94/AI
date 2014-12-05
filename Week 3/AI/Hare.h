#pragma once
#include "BaseUnit.h"
class Hare : public BaseUnit, public std::enable_shared_from_this<Hare>
{

public:
	Hare();
	~Hare();
	//QString img_link;
	//std::shared_ptr<Vertex> vertex;
	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	QString GetImageLink();

	void Move(std::shared_ptr<Graph> graph);
	void Update();
	//void ChangeState(EnumState new_state);
	EnumState GetState();
};

