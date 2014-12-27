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

void MainWindow::showItems(std::shared_ptr<Pill> p_pill, std::shared_ptr<Weapon> p_weapon)
{
	pill = p_pill;
	weapon = p_weapon;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);

	// Paint the sprites
	std::shared_ptr<Cow> t_cow = cow.lock();
	std::shared_ptr<Hare> t_hare = hare.lock();
	std::shared_ptr<Pill> t_pill = pill.lock();
	std::shared_ptr<Weapon> t_weapon = weapon.lock();

	QImage img_cow(t_cow->GetImageLink());
	QImage img_hare(t_hare->GetImageLink());
	QImage img_pill(QDir::currentPath().append("/Resources/pill.png"));
	QImage img_weapon(QDir::currentPath().append("/Resources/weapon.png"));

	QImage overlay_cow(t_cow->GetImageLink());
	QImage overlay_hare(t_hare->GetImageLink());
	QImage overlay_pill(QDir::currentPath().append("/Resources/pill.png"));
	QImage overlay_weapon(QDir::currentPath().append("/Resources/weapon.png"));

	overlay_cow.fill(qRgba(255, 0, 0, 75));
	overlay_hare.fill(qRgba(0, 255, 0, 75));
	overlay_pill.fill(qRgba(0, 0, 255, 75));
	overlay_weapon.fill(qRgba(255, 255, 0, 75));

	painter.drawImage(t_cow->GetPosition().x() - img_cow.width() / 2, t_cow->GetPosition().y() - img_cow.height() / 2, img_cow);
	painter.drawImage(t_hare->GetPosition().x() - img_hare.width() / 2, t_hare->GetPosition().y() - img_hare.height() / 2, img_hare);
	painter.drawImage(t_pill->GetPosition().x() - img_pill.width() / 2, t_pill->GetPosition().y() - img_pill.height() / 2, img_pill);
	painter.drawImage(t_weapon->GetPosition().x() - img_weapon.width() / 2, t_weapon->GetPosition().y() - img_weapon.height() / 2, img_weapon);

	painter.drawImage(t_cow->GetPosition().x() - img_cow.width() / 2, t_cow->GetPosition().y() - img_cow.height() / 2, overlay_cow);
	painter.drawImage(t_hare->GetPosition().x() - img_hare.width() / 2, t_hare->GetPosition().y() - img_hare.height() / 2, overlay_hare);
	painter.drawImage(t_pill->GetPosition().x() - img_pill.width() / 2, t_pill->GetPosition().y() - img_pill.height() / 2, overlay_pill);
	painter.drawImage(t_weapon->GetPosition().x() - img_weapon.width() / 2, t_weapon->GetPosition().y() - img_weapon.height() / 2, overlay_weapon);

	// Check state from cow and show on screen
	QString cow_state = QString("The cow is ");
	cow_state.append(QString::fromUtf8(t_cow->GetAction().c_str()));

	// Check state from hare and show on screen
	QString hare_state = QString("The hare is ");
	hare_state.append(QString::fromUtf8(t_hare->GetAction().c_str()));

	painter.setPen(QPen(QColor(Qt::black), 3 , Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
	QFont times_font("times", 20);
	painter.setFont(times_font);

	painter.drawText(450, 30, cow_state);
	painter.drawText(450, 60, hare_state);

	// Check scores frome hare and cow and show on screen
	QString cow_score = QString("Cow: %1").arg(t_cow->GetPoints());
	QString hare_score = QString("Hare: %1").arg(t_hare->GetPoints());

	painter.drawText(10, 30, cow_score);
	painter.drawText(10, 60, hare_score);
}

void MainWindow::PaintImage(QImage* image, QRgb color)
{
	QPainter paint(image);
	paint.setCompositionMode(QPainter::CompositionMode_Overlay);
	paint.fillRect(image->rect(), color);
	paint.setOpacity(0.5);
	paint.end();
}

MainWindow::~MainWindow()
{
}
