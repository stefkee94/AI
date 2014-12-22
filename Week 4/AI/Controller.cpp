#include "Controller.h"

int cow_x = 50;
int cow_y = 500;
int hare_x = 50;
int hare_y = 200;

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();

	cow->SetPosition(QVector2D(cow_x, cow_y));
	hare->SetPosition(QVector2D(hare_x, hare_y));
	
	mainWindow = new MainWindow();
	mainWindow->setWindowTitle(QObject::tr("Week 2 AI, FSM"));
	mainWindow->resize(width_view, height_view);
	mainWindow->show();

	std::thread* game_loop = new std::thread(&Controller::Start, this);
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

double Controller::GetWidth()
{
	return width_view;
}

double Controller::GetHeight()
{
	return height_view;
}

void Controller::Start()
{
	start_time = std::clock();
	is_running = true;

	while (is_running)
	{
		// Calculate dt
		double current_time = std::clock();
		double elapsed_time = (current_time - start_time) / 1000;

		// Update
		Update(elapsed_time);
		Repaint();
		
		// Sleep
		std::chrono::milliseconds dura(10);
		std::this_thread::sleep_for(dura);
	}
}

void Controller::Update(double elapsed_time)
{
	std::vector<std::shared_ptr<Vertex>> route_cow, route_hare;
	
	//// Update the units
	hare->Update(this, elapsed_time);
	cow->Update(this, elapsed_time);

	//// Get the routes of the units
	//route_hare = hare->Move(0/*dt*/);
	//route_cow = cow->Move(0/*dt*/);

	//// Move the units
	//MoveHare(route_hare);
	//MoveCow(route_cow);
}

void Controller::Repaint()
{
	mainWindow->showGraph(this);
	mainWindow->showPlayers(cow, hare);
	mainWindow->update();
	qApp->processEvents();
}

void Controller::RespawnCow()
{
}

void Controller::RespawnHare()
{
}