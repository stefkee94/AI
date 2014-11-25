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
	mainWindow->show();
}

void Controller::MoveCow()
{
	graph.Search(cow->GetVertex(), hare->GetVertex(), cow, hare);
	std::vector<std::shared_ptr<Vertex>> vertices = graph.getPositions();
	for (int i = 0; i < vertices.size() - 1; i++)
	{
		std::shared_ptr<Hare> tmp_hare = vertices[i]->GetHare();
		std::shared_ptr<Cow> tmp_cow = vertices[i]->GetCow();
		if (tmp_hare != nullptr && tmp_cow != nullptr)
		{
			if (tmp_hare->GetVertex()->getWeight() == tmp_cow->GetVertex()->getWeight())
			{
				MoveHare(i);
				break;
			}
			
		}
	}
}

void Controller::MoveHare(int prev_position)
{
	// Only called when the cow is on the same position as the hare
	// Move the hare to a random position
	graph.MoveHare(hare, prev_position);
}