#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();

	graph.Init(cow, hare);
	
	mainWindow = new MainWindow();
	mainWindow->setWindowTitle(QObject::tr("Week 1 AI"));
	mainWindow->resize(1000,500);
	mainWindow->show();

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
	std::vector<std::shared_ptr<Vertex>> route = graph.GetRoute(cow->GetVertex(), hare->GetVertex());
	MoveCow(route);
}

void Controller::Repaint()
{
	mainWindow->showGraph(graph, this);
	mainWindow->showPlayers(cow, hare);
	mainWindow->repaint();
}

void Controller::MoveCow(std::vector<std::shared_ptr<Vertex>> route)
{
	for (int i = 1; i < route.size(); i++)
	{
		// Move the cow
		cow->SetVertex(route.at(i));

		// Repaint the view to show the movement
		Repaint();

		// Let the thread sleep for 2 seconds
		std::chrono::milliseconds dura(2000);
		std::this_thread::sleep_for(dura);
	}
}

void Controller::MoveHare(int prev_position)
{
	// Only called when the cow is on the same position as the hare
	// Move the hare to a random position
	graph.MoveHare(hare, prev_position);
}