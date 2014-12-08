#pragma once

#include <random>
#include <memory>
#include "Vertex.h"

class Utils
{
private:
	static int seed;
	static std::mt19937 rng;
public:
	Utils();
	~Utils();

	static std::string ToLowerCase(std::string string);
	static int RandomNumber(int max);
	static int RandomNumber(int min, int max);
	static bool InRange(std::shared_ptr<Vertex> param1, std::shared_ptr<Vertex> param2);
};