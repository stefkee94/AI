#pragma once

#include <qvector2d.h>

class Item
{
public:
	Item();
	~Item();

	// Getters
	virtual QVector2D GetPosition();

	// Setters
	virtual void SetPosition(QVector2D position);

private:
	QVector2D position;
};

