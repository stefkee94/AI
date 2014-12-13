#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();
	
	mainWindow = new MainWindow();
	mainWindow->setWindowTitle(QObject::tr("Week 2 AI, FSM"));
	mainWindow->resize(1000,500);
	mainWindow->show();

	std::thread* game_loop = new std::thread(&Controller::Start, this);
	//QThread* game_loop = new QThread(&Controller::Start, this);
	Repaint();
}

Controller::~Controller()
{
}

std::shared_ptr<Cow> Controller::GetCow()
{
	return cow;
}

std::shared_ptr<Hare> Controller::GetHare()
{
	return hare;
}

void Controller::Start()
{
	is_running = true;
	while (is_running)
	{
		Update();
		Repaint();
		
		// Sleep
		std::chrono::milliseconds dura(2000);
		std::this_thread::sleep_for(dura);
	}
}

void Controller::Update()
{
	std::vector<std::shared_ptr<Vertex>> route_cow, route_hare;

	// Update the units
	hare->Update(this);
	cow->Update(this);

	// Get the routes of the units
	route_hare = hare->Move();
	route_cow = cow->Move();

	// Move the units
	MoveHare(route_hare);
	MoveCow(route_cow);
}

void Controller::Repaint()
{
	mainWindow->showGraph(this);
	mainWindow->showPlayers(cow, hare);
	mainWindow->update();
	qApp->processEvents();
}

void Controller::MoveCow(std::vector<std::shared_ptr<Vertex>> route_cow)
{
	//std::vector<std::shared_ptr<Vertex>> route = graph->GetShortestChaseRoute();
	if (route_cow.size() > 0)
	{
		for (int i = 0; i < route_cow.size(); i++)
		{
			if (route_cow.at(i) != cow->GetVertex() && route_cow.at(i) != nullptr)
			{
				cow->SetVertex(route_cow.at(i));
				break;
			}
		}
	}
}

//graph->MoveHare(hare);
void Controller::MoveHare(std::vector<std::shared_ptr<Vertex>> route_hare)
{
	//std::vector<std::shared_ptr<Vertex>> route = graph->GetShortestChaseRoute();
	if (route_hare.size() > 0)
	{
		for (int i = 0; i < route_hare.size(); i++)
		{
			if (route_hare.at(i) != hare->GetVertex() && route_hare.at(i) != nullptr)
			{
				hare->SetVertex(route_hare.at(i));
				break;
			}
		}
	}
}

void Controller::RespawnCow()
{
}

void Controller::RespawnHare()
{
}