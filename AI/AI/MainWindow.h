#pragma once
#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <qpainter.h>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	void paintEvent(QPaintEvent *e);
};

