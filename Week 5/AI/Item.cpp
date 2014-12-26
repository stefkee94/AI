#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}


QVector2D Item::GetPosition()
{
	return position;
}


void Item::SetPosition(QVector2D position)
{
	this->position = position;
}