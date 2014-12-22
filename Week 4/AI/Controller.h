#pragma once

#include <iostream>
#include <QObject>
#include <QtWidgets>
#include <memory>
#include <chrono>
#include <ctime>
#include <thread>

#include "MainWindow.h"
#include "Cow.h"
#include "Hare.h"

class MainWindow;
class Controller : public QObject
{
	Q_OBJECT

public:
	Controller();
	virtual ~Controller();

	std::shared_ptr<Cow> GetCow();
	std::shared_ptr<Hare> GetHare();

	double GetWidth();
	double GetHeight();

	void RespawnCow();
	void RespawnHare();

private:
	bool is_running;
	int sleep_counter = -1; // Init on -1 (non availble) and 0 = available
	double start_time;
	double width_view = 1280;
	double height_view = 720;

	// QT init
	MainWindow* mainWindow;

	// Variables
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;

	// Functions
	void Start();
	void MoveUnits();
	void Update(double);
	void Repaint();
	

};

