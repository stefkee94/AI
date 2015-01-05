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

	//Set the begin numbers for the chance instances
	pill_number = Utils::RandomNumber(10, 30);
	flee_number = Utils::RandomNumber(10, 30);
	weapon_number = Utils::RandomNumber(10, 30);
	hide_number = Utils::RandomNumber(10, 30);

	NextGeneration();

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
			RespawnItems();
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

			// Make changes before next generation starts
			PrepareNextGeneration();
			
			// Calculate the next generation
			NextGeneration();

			//Respawn the cow and hare
			ResetCow();
			ResetHare();
			RespawnItems();

			// Show the user you are in a other round
			std::cout << "Next round! " << round << std::endl;
		}
	}
}

void Controller::PrepareNextGeneration()
{
	// Genetic algorithm
	int points_pill_cow = cow->GetPointsFindPillCow();
	int points_weapon_cow = cow->GetPointsFindWeaponCow();
	int points_hiding_cow = cow->GetPointsHidingCow();
	int points_fleeing_cow = cow->GetPointsFleeingCow();

	// Create a collection of the points
	std::vector<std::pair<EnumState, int>> collection;
	collection.push_back(std::pair<EnumState, int>(EnumState::COW_FIND_PILL, points_pill_cow));
	collection.push_back(std::pair<EnumState, int>(EnumState::COW_FIND_WEAPON, points_weapon_cow));
	collection.push_back(std::pair<EnumState, int>(EnumState::COW_HIDING, points_hiding_cow));
	collection.push_back(std::pair<EnumState, int>(EnumState::COW_FLEEING, points_fleeing_cow));

	// Sort the collection
	std::sort(collection.begin(), collection.end(), [](std::pair<EnumState, int>& first_elem, std::pair<EnumState, int>& second_elem)
	{
		return first_elem.second > second_elem.second;
	});

	// Select highest
	bool different_numbers = false;
	for (int i = 0; i < collection.size(); i++)
	{
		if (collection.at(0).second != collection.at(i).second)
		{
			different_numbers = true;
			break;
		}
	}

	std::pair<EnumState, int> highest;
	std::pair<EnumState, int> random;

	if (different_numbers)
	{
		highest = collection.at(0);
		random = collection.at(Utils::RandomNumber(1, collection.size() - 1));
	}
	else
	{
		int a, b;
		a = Utils::RandomNumber(collection.size() - 1);

		do
		{
			b = Utils::RandomNumber(collection.size() - 1);
		} while (a == b);

		highest = collection.at(a);
		random = collection.at(b);
	}

	// Change state chances
	for (int i = 0; i < 2; i++)
	{
		std::pair<EnumState, int> temp;
		if (i == 0)
			temp = highest;
		else
			temp = random;

		// Change the chance of the selected state
		switch (temp.first)
		{
			case EnumState::COW_FIND_PILL:
				pill_number += 10;
				break;
			case EnumState::COW_FIND_WEAPON:
				weapon_number += 10;
				break;
			case EnumState::COW_HIDING:
				hide_number += 10;
				break;
			case EnumState::COW_FLEEING:
				flee_number += 10;
				break;
		}
	}
}

void Controller::NextGeneration()
{
	// Clear the numbers array
	numbers.clear();
	
	// Calculate the next generation
	int total = pill_number + flee_number + weapon_number + hide_number;

	pill_number = pill_number * 100 / total;
	flee_number = flee_number * 100 / total;
	weapon_number = weapon_number * 100 / total;
	hide_number = hide_number * 100 / total;

	numbers.push_back(pill_number);
	numbers.push_back(pill_number + flee_number);
	numbers.push_back(pill_number + flee_number + weapon_number);
	numbers.push_back(pill_number + flee_number + weapon_number + hide_number);

	// Print the generation numbers
	std::cout << "pill:   " << pill_number << std::endl;
	std::cout << "flee:   " << flee_number << std::endl;
	std::cout << "weapon: " << weapon_number << std::endl;
	std::cout << "hide:   " << hide_number << std::endl;
	std::cout << std::endl;
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
	pill->SetPosition(QVector2D(Utils::RandomNumber(150, GetWidth() - 150), Utils::RandomNumber(150, GetHeight() - 150)));
	weapon->SetPosition(QVector2D(Utils::RandomNumber(150, GetWidth() - 150), Utils::RandomNumber(150, GetHeight() - 150)));
}

std::vector<int> Controller::GetNumbers()
{
	return numbers;
}

void Controller::SetNumber(int number, int placeOfNumber)
{
	numbers[placeOfNumber] = number;
}