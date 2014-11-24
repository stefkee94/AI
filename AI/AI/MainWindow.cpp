#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
{
}

void MainWindow::showGraph(Graph graph, Controller* p_controller)
{
	controller = p_controller;
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
		controller->Click();
	}
}

void MainWindow::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	for (int i = 0; i < vertices.size(); i++)
	{
		painter.setBrush(Qt::darkBlue);
		painter.drawEllipse(vertices[i]->getXPos() - 10, vertices[i]->getYPos() - 10, 20, 20);
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

	painter.drawImage(t_cow->GetVertex()->getXPos() - img_cow.width() / 2, t_cow->GetVertex()->getYPos() - img_cow.height() / 2, img_cow);
	painter.drawImage(t_hare->GetVertex()->getXPos() - img_hare.width() / 2, t_hare->GetVertex()->getYPos() - img_hare.height() / 2, img_hare);
}

MainWindow::~MainWindow()
{
}
