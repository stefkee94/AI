#include "Controller.h"

Controller::Controller() : QObject()
{
	Graph graph = Graph();

	mainWindow.setWindowTitle(QObject::tr("Week 1 AI"));
	mainWindow.resize(640, 360);
	mainWindow.show();
}

Controller::~Controller()
{

}


void Controller::Click()
{
	// Handle user input click
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

