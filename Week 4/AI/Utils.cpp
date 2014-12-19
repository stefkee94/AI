#include "Utils.h"

int Utils::seed = std::random_device()();
std::mt19937 Utils::rng = std::mt19937(Utils::seed);

Utils::Utils()
{
}


Utils::~Utils()
{
}

std::string Utils::ToLowerCase(std::string string)
{
	for (int i = 0; i < string.length(); i++)
	{
		string[i] = tolower(string[i]);
	}
	return string;
}

int Utils::RandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max)(rng);
}

int Utils::RandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}

double Utils::RandomClamped()
{
	return std::uniform_real_distribution<double>(-1, 1)(rng);
}

bool Utils::InRange(std::shared_ptr<Vertex> param1, std::shared_ptr<Vertex> param2)
{
	/*std::vector<std::shared_ptr<Edge>> edges = param1->GetEdges();
	for (std::shared_ptr<Edge> edge : edges)
	{
		std::vector<std::shared_ptr<Vertex>> dests = edge->GetDestinations();
		for (std::shared_ptr<Vertex> vertex : dests)
		{
			if (vertex == param2)
			{
				std::cout << "IN RANGE" << std::endl;
				return true;
			}
		}
	}*/
	return false;
}