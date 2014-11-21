#include <QtWidgets>
#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
{

}

void MainWindow::paintEvent(QPaintEvent *e)
{
	//QPainter painter(this);
	//painter.setPen(Qt::red);
	//painter.setBrush(Qt::blue);

	////painter.drawRect(QRect(100, 100, 100, 100));
	//QImage image(QDir::currentPath().append("\Resource\chicken.png"));
	//painter.drawImage(QPoint(100, 100), image);
}

MainWindow::~MainWindow()
{
}
