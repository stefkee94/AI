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
}

void MainWindow::showPlayers(std::shared_ptr<Cow> p_cow, std::shared_ptr<Hare> p_hare)
{
	cow = p_cow;
	hare = p_hare;
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
		painter.drawEllipse(vertices[i]->getXPos(), vertices[i]->getYPos(), 20, 20);
	}

	for (int j = 0; j < edges.size(); j++)
	{
		painter.setPen(QPen(QColor(Qt::red), 3, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
		painter.drawLine(edges[j]->GetDestinations()[0]->getXPos(), edges[j]->GetDestinations()[0]->getYPos(),
			edges[j]->GetDestinations()[1]->getXPos(), edges[j]->GetDestinations()[1]->getYPos());
	}

	// Paint the sprites
	std::shared_ptr<Cow> t_cow = cow.lock();
	std::shared_ptr<Hare> t_hare = hare.lock();

	QImage img_cow(t_cow->GetImageLink());
	QImage img_hare(t_hare->GetImageLink());

	painter.drawImage(t_cow->GetVertex()->getXPos(), t_cow->GetVertex()->getYPos(), img_cow);
	painter.drawImage(t_hare->GetVertex()->getXPos(), t_hare->GetVertex()->getYPos(), img_hare);

	//QRectF target(edges[0].GetDestinations()[0].getXPos()-10, edges[0].GetDestinations()[0].getYPos()-10, 50.0, 50.0);
	//QRectF source(0.0, 0.0, 70.0, 40.0);
	//QImage image("C:\\42IN14SAi\\chicken.png");
	//painter.drawImage(target, image, source);

	//QRectF target2(edges[2].GetDestinations()[0].getXPos() - 10, edges[2].GetDestinations()[0].getYPos() - 10, 50.0, 50.0);
	//QRectF source2(0.0, 0.0, 70.0, 40.0);
	//QImage image2("C:\\42IN14SAi\\cow.png");
	//painter.drawImage(target2, image2, source2);
	// Not working 
}

MainWindow::~MainWindow()
{
}
