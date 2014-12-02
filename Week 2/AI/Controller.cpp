#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();

	graph = std::make_shared<Graph>();
	graph->Init(cow, hare);
	
	mainWindow = new MainWindow();
	mainWindow->setWindowTitle(QObject::tr("Week 1 AI"));
	mainWindow->resize(1000,500);
	mainWindow->show();

	std::thread* game_loop = new std::thread(&Controller::Start, this);
	//QThread* game_loop = new QThread(&Controller::Start, this);
	Repaint();
}

Controller::~Controller()
{
}

void Controller::Click()
{
	Update();
}

void Controller::Start()
{
	is_running = true;
	while (is_running)
	{
		Update();
		Repaint();
		// Sleep
		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);
	}
}

void Controller::Update()
{
	cow->Move(graph);
	cow->Update();
	//std::vector<std::shared_ptr<Vertex>> route = graph.GetRoute(cow->GetVertex(), hare->GetVertex());
	MoveCow(graph->GetShortestChaseRoute());
	//Repaint();
}

void Controller::Repaint()
{
	mainWindow->showGraph(graph, this);
	mainWindow->showPlayers(cow, hare);
	//mainWindow->repaint();
	mainWindow->update();
	//qApp->processEvents();
}

void Controller::MoveCow(std::vector<std::shared_ptr<Vertex>> route)
{
	for (int i = 0; i < route.size(); i++)
	{
		// Move the cow
		cow->SetVertex(route.at(i));

		// Repaint the view to show the movement
		Repaint();

		// Let the thread sleep for 2 seconds
		std::chrono::milliseconds dura(500);
		std::this_thread::sleep_for(dura);
	}

	if (cow->GetVertex() == hare->GetVertex())
		MoveHare();
}

void Controller::MoveHare()
{
	graph->MoveHare(hare);
}