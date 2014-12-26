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
#include "Pill.h"
#include "Weapon.h"

class MainWindow;
class Controller : public QObject
{
	Q_OBJECT

public:
	Controller();
	virtual ~Controller();

	std::shared_ptr<Cow> GetCow();
	std::shared_ptr<Hare> GetHare();
	std::shared_ptr<Pill> GetPill();
	std::shared_ptr<Weapon> GetWeapon();

	double GetWidth();
	double GetHeight();

	void RespawnCow();
	void RespawnHare();

private:
	bool is_running;
	int sleep_counter = -1; // Init on -1 (non availble) and 0 = available
	int round;
	double start_time;
	double width_view = 800;
	double height_view = 800;
	double timer;
	int cow_x = 600;
	int cow_y = 400;
	int hare_x = 200;
	int hare_y = 400;

	// QT init
	MainWindow* mainWindow;

	// Variables
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;
	std::shared_ptr<Pill> pill;
	std::shared_ptr<Weapon> weapon;

	// Functions
	void Start();
	void MoveUnits();
	void Update(double);
	void Repaint();
	

};

