#include "Controller.h"
#include "Utils.h"

Controller::Controller() : QObject()
{
	// Create MainWindow
	mainWindow = new MainWindow();
	mainWindow->setWindowTitle(QObject::tr("Week 2 AI, FSM"));
	mainWindow->resize(width_view, height_view);
	mainWindow->show();

	// Create entities and items
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();
	pill = std::make_shared<Pill>();
	weapon = std::make_shared<Weapon>();

	// Place the entities and items
	cow->SetPosition(QVector2D(cow_x, cow_y));
	hare->SetPosition(QVector2D(hare_x, hare_y));
	pill->SetPosition(QVector2D(Utils::RandomNumber(GetWidth()), Utils::RandomNumber(GetHeight())));
	weapon->SetPosition(QVector2D(Utils::RandomNumber(GetWidth()), Utils::RandomNumber(GetHeight())));

	// Start game loop
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

std::shared_ptr<Pill> Controller::GetPill()
{
	return pill;
}

std::shared_ptr<Weapon> Controller::GetWeapon()
{
	return weapon;
}

double Controller::GetWidth()
{
	return mainWindow->width();
}

double Controller::GetHeight()
{
	return mainWindow->height();
}

void Controller::Start()
{
	start_time = std::clock();
	is_running = true;
	timer = 30000;
	round = 0;

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
	if (timer > 0)
	{
		// Update the units
		hare->Update(this, elapsed_time);
		cow->Update(this, elapsed_time);

		// Check if the hare caught the cow
		if ((cow->GetPosition() - hare->GetPosition()).length() < 2)
		{
			hare->AddPoints(cow->Caught(this));
		}

		// Decrease timer with the elapsed time
		timer -= elapsed_time;
	}
	else
	{
		if (round == 5)
		{
			is_running = false;

			// Show the user you are finished
			std::cout << "Finished!" << std::endl;
		}
		else
		{
			// Restart the timer and increase the round.
			round++;
			start_time = std::clock();
			timer = 30000;

			//Respawn the cow and hare
			ResetCow();
			ResetHare();
			RespawnItems();

			// Show the user you are in a other round
			std::cout << "Next round! " << round << std::endl;
		}
	}
}

void Controller::Repaint()
{
	mainWindow->showGraph(this);
	mainWindow->showPlayers(cow, hare);
	mainWindow->showItems(pill, weapon);
	mainWindow->update();
	qApp->processEvents();
}

void Controller::ResetCow()
{
	cow->Reset();
	cow->SetPosition(QVector2D(cow_x, cow_y));
}

void Controller::ResetHare()
{
	hare->Reset();
	hare->SetPosition(QVector2D(hare_x, hare_y));
}

void Controller::RespawnCow()
{
	cow->Respawn();
	cow->SetPosition(QVector2D(cow_x, cow_y));
}

void Controller::RespawnHare()
{
	hare->Respawn();
	hare->SetPosition(QVector2D(hare_x, hare_y));
}

void Controller::RespawnPill()
{
	pill->SetPosition(QVector2D(Utils::RandomNumber(GetWidth()), Utils::RandomNumber(GetHeight())));
}

void Controller::RespawnWeapon()
{
	weapon->SetPosition(QVector2D(Utils::RandomNumber(GetWidth()), Utils::RandomNumber(GetHeight())));
}

void Controller::RespawnItems()
{
	pill->SetPosition(QVector2D(Utils::RandomNumber(GetWidth()), Utils::RandomNumber(GetHeight())));
	weapon->SetPosition(QVector2D(Utils::RandomNumber(GetWidth()), Utils::RandomNumber(GetHeight())));
}