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
	virtual void SetPoints(int points);
	virtual void AddPoints(int points);

	virtual QString GetImageLink();
	virtual EnumState GetEnumState();
	virtual std::string GetAction();
	virtual QVector2D GetPosition();
	virtual bool HasPill();
	virtual bool HasWeapon();
	virtual int GetPoints();

protected:
	QVector2D Position;
	BehaviorState* state;
	EnumState currentEnumState;
	QString img_link;
	bool weapon = false;
	bool pill = false;
	int points;
};