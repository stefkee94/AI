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
	virtual void Respawn() = 0;
	virtual void Update(Controller* controller, double time_elapsed) = 0;

	virtual void SetPosition(QVector2D position);
	virtual void SetState(BehaviorState* state);

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