#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();

	graph.Init(cow, hare);
	
	mainWindow.setWindowTitle(QObject::tr("Week 1 AI"));
	mainWindow.resize(1000,500);
	
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

}

void Controller::Repaint()
{
	mainWindow.showGraph(graph);
	mainWindow.showPlayers(cow, hare);
	mainWindow.show();//QWidget::update();
}

void Controller::MoveCow()
{
	// Move the cow to the position closest to the hare
}

void Controller::MoveHare()
{
	// Only called when the cow is on the same position as the hare
	// Move the hare to a random position
}