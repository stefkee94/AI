#include "MainWindow.h"
#include <qdir.h>

MainWindow::MainWindow(QWidget *parent)
{
}

void MainWindow::showGraph(Controller* p_controller)
{
	controller = p_controller;
}

void MainWindow::showPlayers(std::shared_ptr<Cow> p_cow, std::shared_ptr<Hare> p_hare)
{
	cow = p_cow;
	hare = p_hare;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	//QImage img_pill(QDir::currentPath().append("/Resources/pill.png"));
	//QImage img_weapon(QDir::currentPath().append("/Resources/weapon.png"));

	// Paint the sprites
	std::shared_ptr<Cow> t_cow = cow.lock();
	std::shared_ptr<Hare> t_hare = hare.lock();

	QImage img_cow(t_cow->GetImageLink());
	QImage img_hare(t_hare->GetImageLink());

	painter.drawImage(t_cow->GetPosition().x() - img_cow.width() / 2, t_cow->GetPosition().y() - img_cow.height() / 2, img_cow);
	painter.drawImage(t_hare->GetPosition().x() - img_hare.width() / 2, t_hare->GetPosition().y() - img_hare.height() / 2, img_hare);

	// Check state from cow and show on screen
	QString cow_state = QString("The cow is ");
	cow_state.append(QString::fromUtf8(t_cow->GetAction().c_str()));

	// Check state from hare and show on screen
	QString hare_state = QString("The hare is ");
	hare_state.append(QString::fromUtf8(t_hare->GetAction().c_str()));

	painter.setPen(QPen(QColor(Qt::black), 3 , Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
	QFont times_font("times", 24);
	painter.setFont(times_font);

	painter.drawText(430, 30, cow_state);
	painter.drawText(430, 60, hare_state);
}

MainWindow::~MainWindow()
{
}
