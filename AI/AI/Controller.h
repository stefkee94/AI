#pragma once

#include <iostream>
#include <QObject>
#include <QtWidgets>
#include <memory>

#include "MainWindow.h"
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
	bool is_running;

	// QT init
	MainWindow mainWindow;

	// Variables
	Graph graph;
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;

	// Functions
	void Start();
	void Click();
	void MoveCow();
	void MoveHare();
	void Update();
	void Repaint();


};

