#include <QtWidgets>
#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{ 
}

void MainWindow::showGraph(Graph graph)
{
	graph = graph;
	vertices = graph.getPositions();
	edges = graph.getEdges();
	QWidget::update();

	showPlayers(graph);
}

void MainWindow::showPlayers(Graph graph)
{
	
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	if (e->key() == Qt::Key_Space)
	{
		std::cout << "space key pressed " << std::endl;
		// search closest and move
		//graph.Search()
	}
}
void MainWindow::paintEvent(QPaintEvent *e)
{

	QPainter painter(this);
	for (int i = 0; i < vertices.size(); i++)
	{
		painter.setBrush(Qt::darkBlue);
		painter.drawEllipse(vertices[i].getXPos(), vertices[i].getYPos(), 20, 20);
	}

	for (int j = 0; j < edges.size(); j++)
	{
		painter.setPen(QPen(QColor(Qt::red), 3, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
		painter.drawLine(edges[j].GetDestinations()[0].getXPos(), edges[j].GetDestinations()[0].getYPos(),
						 edges[j].GetDestinations()[1].getXPos(),edges[j].GetDestinations()[1].getYPos());
	}
	QRectF target(edges[0].GetDestinations()[0].getXPos()-10, edges[0].GetDestinations()[0].getYPos()-10, 50.0, 50.0);
	QRectF source(0.0, 0.0, 70.0, 40.0);
	QImage image("C:\\42IN14SAi\\chicken.png");
	painter.drawImage(target, image, source);

	QRectF target2(edges[2].GetDestinations()[0].getXPos() - 10, edges[2].GetDestinations()[0].getYPos() - 10, 50.0, 50.0);
	QRectF source2(0.0, 0.0, 70.0, 40.0);
	QImage image2("C:\\42IN14SAi\\cow.png");
	painter.drawImage(target2, image2, source2);
	// Not working 
	/*QImage img("C:\42IN14SAi\chicken.png");
	painter.drawImage(QRect(100, 50, 100, 100), img);*/
}

MainWindow::~MainWindow()
{
}
