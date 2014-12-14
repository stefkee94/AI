#include "BaseUnit.h"

QString BaseUnit::GetImageLink()
{
	return img_link;
}

std::string BaseUnit::GetAction()
{
	return state->GetAction();
}

EnumState BaseUnit::GetEnumState()
{
	return currentEnumState;
}

QVector2D BaseUnit::GetPosition()
{
	return Position;
}

void BaseUnit::SetPosition(QVector2D position)
{
	this->Position = position;
}