#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();

	graph = std::make_shared<Graph>();
	graph->Init(cow, hare);
	
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
	std::vector<std::shared_ptr<Vertex>> route_cow, route_hare;

	if (hare->GetState() == EnumState::HARE_CHASING && Utils::InRange(hare->GetVertex(), cow->GetVertex()))
	{
		std::cout << "The cow is shot!" << std::endl;

		// Move the hare
		route_hare = hare->Move(graph);
		MoveHare(route_hare);

		// Clear the route and move the cow to a random position
		graph->ClearRoute();
		graph->MoveCow(cow);
	}
	else if (cow->GetState() == EnumState::COW_CHASING && cow->GetVertex() == hare->GetVertex())
	{
		std::cout << "The hare is caught!" << std::endl;
		graph->MoveHare(hare);
	}
	else
	{
		// Get the routes of the hare and the cow
		route_hare = hare->Move(graph);
		route_cow = cow->Move(graph);

		// Move the hare and the cow
		MoveHare(route_hare);
		MoveCow(route_cow);

		// Clear the routes
		graph->ClearRoute();
	}
}

void Controller::Repaint()
{
	mainWindow->showGraph(graph, this);
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