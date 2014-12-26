#pragma once

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <qpainter.h>
#include <memory>
#include <iostream>
#include <qrgb.h>

#include "Cow.h"
#include "Hare.h"
#include "Pill.h"
#include "Weapon.h"
#include "Controller.h"
//#include "EnumState.h"

class Controller;
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	void paintEvent(QPaintEvent *e);
	void showGraph(Controller* p_controller);
	void showPlayers(std::shared_ptr<Cow> p_cow, std::shared_ptr<Hare> p_hare);
	void showItems(std::shared_ptr<Pill> p_pill, std::shared_ptr<Weapon> p_weapon);
	void PaintImage(QImage* image, QRgb color);

private:
	Controller* controller;
	std::vector<std::shared_ptr<Vertex>> vertices;
	std::vector<std::shared_ptr<Edge>> edges;
	std::weak_ptr<Cow> cow;
	std::weak_ptr<Hare> hare;
	std::weak_ptr<Pill> pill;
	std::weak_ptr<Weapon> weapon;
};

