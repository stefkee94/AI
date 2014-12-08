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
	int sleep_counter = 0;

	// QT init
	MainWindow* mainWindow;

	// Variables
	std::shared_ptr<Graph> graph;
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;

	// Functions
	void Start();
	void MoveUnits();
	void MoveCow(std::vector<std::shared_ptr<Vertex>> route_cow);
	void MoveHare(std::vector<std::shared_ptr<Vertex>> route_hare);
	void Update();
	void Repaint();
	

};

