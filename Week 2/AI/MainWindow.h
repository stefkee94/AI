#pragma once

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <qpainter.h>
#include <memory>
#include <iostream>

#include "Graph.h"
#include "Cow.h"
#include "Hare.h"
#include "Controller.h"

class Controller;
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	void paintEvent(QPaintEvent *e);
	void showGraph(Graph graph, Controller* p_controller);
	void showPlayers(std::shared_ptr<Cow> p_cow, std::shared_ptr<Hare> p_hare);

private:
	Controller* controller;
	std::vector<std::shared_ptr<Vertex>> vertices;
	std::vector<std::shared_ptr<Edge>> edges;
	std::weak_ptr<Cow> cow;
	std::weak_ptr<Hare> hare;

protected:
	virtual void keyPressEvent(QKeyEvent* e);
};

