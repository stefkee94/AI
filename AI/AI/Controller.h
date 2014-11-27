#pragma once

#include <iostream>
#include <QObject>
#include <QtWidgets>
#include <memory>
#include <chrono>
#include <thread>

#include "MainWindow.h"
#include "Cow.h"
#include "Hare.h"
#include "Graph.h"

class MainWindow;
class Controller : public QObject
{
	Q_OBJECT

public:
	Controller();
	virtual ~Controller();
	void Click();

private:
	bool is_running;

	// QT init
	MainWindow* mainWindow;

	// Variables
	Graph graph;
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;

	// Functions
	void Start();
	void MoveCow(std::vector<std::shared_ptr<Vertex>> route);
	void MoveHare();
	void Update();
	void Repaint();
	

};

