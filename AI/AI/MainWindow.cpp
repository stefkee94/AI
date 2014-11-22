#include <QtWidgets>
#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
{

}

void MainWindow::showGraph(Graph graph)
{
	vertices = graph.getPositions();
	edges = graph.getEdges();
	QWidget::update();

	showPlayers(graph);
}

void MainWindow::showPlayers(Graph graph)
{
	
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
	// Not working 
	/*QImage img("C:\42IN14SAi\chicken.png");
	painter.drawImage(QRect(100, 50, 100, 100), img);*/
}

MainWindow::~MainWindow()
{
}
