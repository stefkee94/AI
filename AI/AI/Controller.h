#pragma once
#include <QObject>
#include <QWidget>
#include "MainWindow.h"

#include <memory>
#include "Cow.h"
#include "Hare.h"
#include "Graph.h"

class Controller : public QObject
{
	Q_OBJECT

public:
	Controller();
	virtual ~Controller();

private:

	// QT init
	MainWindow mainWindow;
	// Variables
	Graph graph;
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;

	// Functions
	void Click();
	void MoveCow();
	void MoveHare();


};

