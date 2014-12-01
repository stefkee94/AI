#pragma once

#include <memory>
#include <QString>
#include "Vertex.h"

class Hare
{
private:
	std::shared_ptr<Vertex> vertex;
	QString img_link;

public:
	Hare();
	~Hare();

	void SetVertex(std::shared_ptr<Vertex> p_vertex);
	std::shared_ptr<Vertex> GetVertex();
	QString GetImageLink();
};

