#include "Controller.h"

Controller::Controller() : QObject()
{
	cow = std::make_shared<Cow>();
	hare = std::make_shared<Hare>();
	pill = std::make_shared<Pill>();
	weapon = std::make_shared<Weapon>();

	cow->SetPosition(QVector2D(cow_x, cow_y));
	hare->SetPosition(QVector2D(hare_x, hare_y));
	pill->SetPosition(QVector2D(100, 100));
	weapon->SetPosition(QVector2D(700, 700));

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
		if ((cow->GetPosition() - hare->GetPosition()).length() == 0)
		{
			hare->AddPoints(cow->Caught(this));
			
			//Respawn the cow and hare
			RespawnCow();
			RespawnHare();
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
			RespawnCow();
			RespawnHare();

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