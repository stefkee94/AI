#include "MainWindow.h"
#include <qdir.h>

MainWindow::MainWindow(QWidget *parent)
{
}

void MainWindow::showGraph(std::shared_ptr<Graph> graph, Controller* p_controller)
{
	controller = p_controller;
	vertices = graph->getPositions();
	edges = graph->getEdges();
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
	QImage img_pill(QDir::currentPath().append("/Resources/pill.png"));
	QImage img_weapon(QDir::currentPath().append("/Resources/weapon.png"));
	for (int i = 0; i < vertices.size(); i++)
	{
		painter.setBrush(Qt::darkBlue);
		painter.drawEllipse(vertices[i]->getXPos() - 10, vertices[i]->getYPos() - 10, 20, 20);
		if (vertices[i]->hasNewPill())
			painter.drawImage(vertices[i]->getXPos() - img_pill.width() / 2, vertices[i]->getYPos() - img_pill.height() / 2, img_pill);
		if (vertices[i]->hasNewWeapon())
			painter.drawImage(vertices[i]->getXPos() - img_weapon.width() / 2, vertices[i]->getYPos() - img_weapon.height() / 2, img_weapon);
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

	// Check state from cow and show on screen
	QString cow_state;
	switch (t_cow->GetState())
	{
		case EnumState::COW_WANDERING:
			cow_state = "The cow is wandering over the vertices";
			break;
		case EnumState::COW_CHASING:
			cow_state = "The cow is chasing the hare";
			break;
	}

	// Check state from hare and show on screen
	QString hare_state;
	switch (t_hare->GetState())
	{
		case EnumState::HARE_WANDERING:
			hare_state = "The hare is wandering in the field";
			break;
		case EnumState::HARE_CHASING:
			hare_state = "The hare is chasing the cow";
			break;
		case EnumState::HARE_FLEEING:
			hare_state = "The hare is fleeing from the cow";
			break;
		case EnumState::HARE_SEARCHING_WEAPON:
			hare_state = "The hare is searching the weapon now";
			break;
	}

	painter.setPen(QPen(QColor(Qt::black), 3 , Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
	QFont times_font("times", 24);
	painter.setFont(times_font);

	painter.drawText(430, 30, cow_state);
	painter.drawText(430, 60, hare_state);
}

MainWindow::~MainWindow()
{
}
