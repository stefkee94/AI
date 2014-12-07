#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::Init(std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare)
{
	this->hare = hare;
	this->cow = cow;
	// Build the graph
	for (int i = 0; i < 6; i++)
		AddVertex(i);

	for (int j = 0; j < positions.size()-1; j++)
	{
		if (j == 0)
			AddEdges(positions[j], positions[j + 2]);
		if (j == 1)
			AddEdges(positions[j], positions[j + 2]);
		AddEdges(positions[j], positions[j + 1]);
	}
	AddEdges(positions[0], positions[positions.size() - 1]);

	// Add the cow to a vertex
	int posCow = 4;
	cow->SetVertex(positions.at(posCow));
	
	// Add the hare to a vertex
	int posHare = 1;
	hare->SetVertex(positions.at(posHare));
}

void Graph::AddVertex(int i)
{
	switch (i)
	{
		case 0: positions.push_back(std::make_shared<Vertex>(50, 50,   true,  false)); break;
		case 1: positions.push_back(std::make_shared<Vertex>(300, 100, false, false)); break;
		case 2: positions.push_back(std::make_shared<Vertex>(150, 200, false, false)); break;
		case 3: positions.push_back(std::make_shared<Vertex>(400, 300, false, false)); break;
		case 4: positions.push_back(std::make_shared<Vertex>(600, 200, false, false)); break;
		case 5: positions.push_back(std::make_shared<Vertex>(300, 20,  false, true)); break;
	}
}

void Graph::AddEdges(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
	std::shared_ptr<Edge> edge = std::make_shared<Edge>(1000, start, end);
	edges.push_back(edge);
	start->AddObject(edge);
	end->AddObject(edge);
}

std::vector<std::shared_ptr<Vertex>> Graph::GetRoute(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node)
{
	// Clear the routes
	ClearRoute();

	// Add the position of the cow to the closed list
	closed_list.push_back(start_node);

	if (start_node == end_node)
	{
		std::vector<std::shared_ptr<Vertex>> route = CreateRoute();
		return route;
	}

	// Set your current node
	bool found_end_node = true;
	std::shared_ptr<Vertex> current_node = start_node;

	while (found_end_node)
	{
		// Get all the neighbours of your current position
		std::vector<std::shared_ptr<Vertex>> neighbours;
		std::vector<std::shared_ptr<Edge>> connections = current_node->GetEdges();
		for (int x = 0; x < connections.size(); x++)
		{
			std::vector<std::shared_ptr<Vertex>> positions = connections.at(x)->GetDestinations();
			for (int y = 0; y < positions.size(); y++)
			{
				if (positions.at(y) != current_node && std::find(closed_list.begin(), closed_list.end(), positions.at(y)) == closed_list.end())
					neighbours.push_back(positions.at(y));
			}
		}

		// Estimate the distance of all the neighbours
		std::map<std::shared_ptr<Vertex>, int> distances;
		for (int i = 0; i < neighbours.size(); i++)
		{
			int distance = EstimateDistance(neighbours.at(i), start_node, end_node);
			distances[neighbours.at(i)] = distance;
		}

		// Create an ordered list
		std::vector<PositionNode> ordered_list;
		for (int x = 0; x < neighbours.size(); x++)
		{
			// Create a new position
			PositionNode position_node = PositionNode(neighbours.at(x), distances[neighbours.at(x)]);

			// Check if list is empty or not
			if (x == 0)
				ordered_list.push_back(position_node);
			else
			{
				int position = neighbours.size();
				for (int y = ordered_list.size() - 1; y >= 0; y--)
				{
					if (distances[neighbours.at(x)] < ordered_list.at(y).GetDistance())
					{
						if (y == 0)
							ordered_list.insert(ordered_list.begin(), position_node);
						else
							position = y;
					}
					else
					{
						if (position >= 0 && position < ordered_list.size())
							ordered_list.insert(ordered_list.begin() + position, position_node);
						else
							ordered_list.push_back(position_node);
						break;
					}
				}
			}
		}

		// Fill the open list with the ordered neighbours
		FillOpenList(ordered_list);

		// Add the shortest item to the closed list and remove it from the open_list
		if (open_list.size() > 0)
		{
			closed_list.push_back(open_list.at(0).GetVertex());
			open_list.erase(open_list.begin());
		}

		if (closed_list.at(closed_list.size() - 1) == end_node)
			found_end_node = false;
		else
			current_node = closed_list.at(closed_list.size() - 1);
	}

	// Create the final route
	std::vector<std::shared_ptr<Vertex>> route = CreateRoute();
	return route;
}

void Graph::FillOpenList(std::vector<PositionNode> ordered_list)
{
	bool empty_list = open_list.size() == 0;
	for (int x = 0; x < ordered_list.size(); x++)
	{
		// Check if the open list is empty
		if (empty_list)
		{
			open_list = ordered_list;
			break;
		}
		else
		{
			bool contains = false;
			// Check if the open list already contains the current vertex
			for (int y = 0; y < open_list.size(); y++)
			{
				if (open_list.at(y).GetVertex() == ordered_list.at(x).GetVertex())
				{
					if (open_list.at(y).GetDistance() > ordered_list.at(x).GetDistance())
						open_list.erase(open_list.begin() + y);
					else
						contains = true;
				}
			}

			if (!contains)
			{
				// Add the vertex to the open list.
				bool inserted = false;
				for (int y = 0; y < open_list.size(); y++)
				{
					if (open_list.at(y).GetDistance() > ordered_list.at(x).GetDistance())
					{
						open_list.insert(open_list.begin() + y, ordered_list.at(x));
						inserted = true;
						break;
					}
				}

				if (!inserted)
					open_list.push_back(ordered_list.at(x));
			}
		}
	}
}

int Graph::EstimateDistance(std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node)
{
	int distance = 0;

	std::shared_ptr<Vertex> p_current_node = current_node;
	for (int x = closed_list.size() - 1; x >= 0; x--)
	{
		std::vector<std::shared_ptr<Edge>> connections = p_current_node->GetEdges();
		for (int y = 0; y < connections.size(); y++)
		{
			std::vector<std::shared_ptr<Vertex>> positions = connections.at(y)->GetDestinations();
			for (int i = 0; i < positions.size(); i++)
			{
				if (positions.at(i) == closed_list.at(x))
				{
					distance += connections.at(y)->GetWeight();
					p_current_node = positions.at(i);
					goto end;
				}
			}
		}
		end:;
	}

	// Estimate the distance from current_node to end_node
	int x, y;
	
	// Calculate the difference between the 2 x positions
	if (current_node->getXPos() > end_node->getXPos())
		x = current_node->getXPos() - end_node->getXPos();
	else
		x = end_node->getXPos() - current_node->getXPos();

	// Calculate the difference between the 2 y positions
	if (current_node->getYPos() > end_node->getYPos())
		y = current_node->getYPos() - end_node->getYPos();
	else
		y = end_node->getYPos() - current_node->getYPos();

	// Return the estimated distance
	return distance + sqrt(x*x + y*y);
}

std::vector<std::shared_ptr<Vertex>> Graph::CreateRoute()
{
	std::vector<std::shared_ptr<Vertex>> route;

	// Create a path from the last item of the closed list to the start point
	route.insert(route.begin(), closed_list.at(closed_list.size() - 1));
	for (int x = closed_list.size() - 1; x > 0; x--)
	{
		bool found_position = false;
		std::shared_ptr<Vertex> position;
		std::vector<std::shared_ptr<Edge>> connections = route.at(0)->GetEdges();
		for (int y = 0; y < connections.size(); y++)
		{
			std::vector<std::shared_ptr<Vertex>> positions = connections.at(y)->GetDestinations();
			if (std::find(positions.begin(), positions.end(), closed_list.at(0)) != positions.end())
			{
				position = closed_list.at(0);
				found_position = true;
				x = 0;
				break;
			}
			else
			{
				for(int i = 0; i < positions.size(); i++)
				{
					if (positions.at(i) == closed_list.at(x - 1))
					{
						position = closed_list.at(x - 1);
						found_position = true;
					}
				}
			}
		}

		if (found_position)
			route.insert(route.begin(), position);
	}

	return route;
}

void Graph::MoveHare(std::shared_ptr<Hare> hare)
{
	//int posHare = 5; //TO TEST WITH WEAPON
	int posHare;
	do posHare = Utils::RandomNumber(positions.size() - 1);
	while (positions.at(posHare) == hare->GetVertex());

	hare->SetVertex(positions.at(posHare));
}

std::vector<std::shared_ptr<Vertex>> Graph::getPositions()
{
	return positions;
}

std::vector<std::shared_ptr<Vertex>> CreateWanderingRoute(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node)
{
	std::vector<std::shared_ptr<Vertex>> route;

	route.insert(route.begin(), start_node);
	route.insert(route.begin() + 1, end_node);

	return route;
}

std::vector<std::shared_ptr<Vertex>> Graph::GetShortestChaseRoute()
{
	std::vector<std::shared_ptr<Vertex>> new_empty_route;
	if (closed_list.size() > 0)
		return CreateRoute();
	else
		return new_empty_route;
}

void Graph::ClearRoute()
{
	closed_list.clear();
	open_list.clear();
	distances.clear();
}

std::vector<std::shared_ptr<Edge>> Graph::getEdges()
{
	return edges;
}

std::shared_ptr<Vertex> Graph::GetHarePosition()
{
	return hare->GetVertex();
}

std::shared_ptr<Vertex> Graph::GetCowPosition()
{
	return cow->GetVertex();
}