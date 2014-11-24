#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();

	graph.Init(cow, hare);
	
	mainWindow = new MainWindow();
	mainWindow->setWindowTitle(QObject::tr("Week 1 AI"));
	mainWindow->resize(1000,500);
	
	Repaint();
}

Controller::~Controller()
{
}

void Controller::Click()
{
	Update();
}

void Controller::Update()
{
	MoveCow();
}

void Controller::Repaint()
{
	mainWindow->showGraph(graph, this);
	mainWindow->showPlayers(cow, hare);
	mainWindow->show();//QWidget::update();
}

void Controller::MoveCow()
{
	
}

void Controller::MoveHare()
{
	// Only called when the cow is on the same position as the hare
	// Move the hare to a random position
}