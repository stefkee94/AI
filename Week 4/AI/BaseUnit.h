#pragma once

#include <vector>
#include <memory>
#include <qdir.h>
#include <qstring.h>
#include <qvector2d.h>

#include "EnumState.h"
#include "BehaviorState.h"

class BaseUnit
{
public:
	virtual void Move(double time_elapsed) = 0;
	virtual void Update(double time_elapsed) = 0;

	virtual void SetPosition(QVector2D position);

	virtual QString GetImageLink();
	virtual EnumState GetEnumState();
	virtual std::string GetAction();
	virtual QVector2D GetPosition();

protected:
	QVector2D Position;
	BehaviorState* state;
	EnumState currentEnumState;
	QString img_link;
};