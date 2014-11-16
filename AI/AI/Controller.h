#pragma once

#include <memory>
#include "Cow.h"
#include "Hare.h"
#include "Graph.h"

class Controller
{
private:
	// Variables
	Graph graph;
	std::shared_ptr<Cow> cow;
	std::shared_ptr<Hare> hare;

	// Functions
	void Click();
	void MoveCow();
	void MoveHare();

public:
	Controller();
	~Controller();
};

