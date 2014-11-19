#include "Graph.h"
#include <QApplication>
#include "Controller.h"

int main(int argc, char **argv)
{
	QApplication app(argc, 0);
	std::unique_ptr<Controller> mainController(new Controller());

	//new Graph();
	app.exec();
}
