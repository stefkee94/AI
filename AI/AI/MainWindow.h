#pragma once
#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <qpainter.h>
#include "Graph.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	void paintEvent(QPaintEvent *e);
	void showGraph(Graph graph);
	void showPlayers(Graph graph);

protected:
	virtual void keyPressEvent(QKeyEvent* e);

private:
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;
	QImage image;
	Graph graph;
};

