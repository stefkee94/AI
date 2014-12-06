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
		//std::chrono::milliseconds durat(2000);
		//std::this_thread::sleep_for(durat);

		Update();
		//Repaint();
		// Sleep
		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);
	}
}

void Controller::Update()
{
	if(hare->GetState() == EnumState::HARE_WANDERING) cow->Move(graph);
	hare->Move(graph);
	MoveCow();
	Repaint();
}

void Controller::Repaint()
{
	mainWindow->showGraph(graph, this);
	mainWindow->showPlayers(cow, hare);
	//mainWindow->repaint();
	mainWindow->update();
	qApp->processEvents();
}

void Controller::MoveCow()
{
	std::vector<std::shared_ptr<Vertex>> route = graph->GetShortestChaseRoute();
	if (route.size() > 0)
	{
		if (hare->GetState() == EnumState::HARE_SEARCHING_WEAPON)
		{
			for (int i = 0; i < route.size(); i++)
			{
				hare->SetVertex(route.at(i));
				Repaint();
				std::chrono::milliseconds dura(1000);
				std::this_thread::sleep_for(dura);
			}
			hare->Update(graph);
			hare->ChangeState(EnumState::HARE_CHASING);
			return;
		}

		for (int i = 0; i < route.size(); i++)
		{
			// Check the state of the vertex to choose what to do
			hare->Update(graph);
			if (hare->GetState() != EnumState::HARE_WANDERING)
			{
				graph->ClearRoute();
				break;
			}

			// Move the cow
			cow->SetVertex(route.at(i));
			
			// Repaint the view to show the movement
			Repaint();

			// Let the thread sleep for 2 seconds
			std::chrono::milliseconds dura(1000);
			std::this_thread::sleep_for(dura);
		}

		if (hare->GetState() == EnumState::HARE_FLEEING)
		{
			hare->Move(graph);
			Repaint();
		}

		if (cow->GetVertex() == hare->GetVertex())
		{
			if (cow->GetState() == EnumState::COW_CHASING && hare->GetState() == EnumState::HARE_WANDERING)
			{
				MoveHare();
				hare->Move(graph);
			}
			if (hare->GetState() == EnumState::HARE_CHASING)
			{
				std::shared_ptr<Vertex> new_cow_pos = cow->GetVertex()->GetEdges()[0]->GetDestinations()[0];
				hare->Move(graph);
				cow->SetVertex(new_cow_pos);
			}	
		}
	}
}

void Controller::MoveHare()
{
	graph->MoveHare(hare);
	
}