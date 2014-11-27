#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::Init(std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare)
{
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
	int posCow = 0;
	positions.at(posCow)->SetCow(cow);
	cow->SetVertex(positions.at(posCow));
	
	// Add the hare to a vertex
	int posHare = 4;	
	positions.at(posHare)->SetHare(hare);
	hare->SetVertex(positions.at(posHare));
}

void Graph::AddVertex(int i)
{
	switch (i)
	{
	case 0: positions.push_back(std::make_shared<Vertex>(50, 50)); break;
	case 1: positions.push_back(std::make_shared<Vertex>(300, 100)); break;
	case 2: positions.push_back(std::make_shared<Vertex>(150, 200)); break;
	case 3: positions.push_back(std::make_shared<Vertex>(400, 300)); break;
	case 4: positions.push_back(std::make_shared<Vertex>(600, 200)); break;
	case 5: positions.push_back(std::make_shared<Vertex>(300, 20)); break;
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

	// Add the position of the cow to the closed list
	closed_list.push_back(start_node);

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
		std::vector<std::shared_ptr<Vertex>> ordered_vertex_list;
		std::vector<int> ordered_distance_list;
		for (int x = 0; x < neighbours.size(); x++)
		{
			if (x == 0)
			{
				ordered_vertex_list.push_back(neighbours.at(x));
				ordered_distance_list.push_back(distances[neighbours.at(x)]);
			}
			else
			{
				int position = ordered_distance_list.size();
				for (int y = ordered_distance_list.size() - 1; y >= 0; y--)
				{
					if (distances[neighbours.at(x)] < ordered_distance_list.at(y))
					{
						if (y == 0)
						{
							ordered_vertex_list.insert(ordered_vertex_list.begin(), neighbours.at(x));
							ordered_distance_list.insert(ordered_distance_list.begin(), distances[neighbours.at(x)]);
						}
						else
							position = y;
					}
					else
					{
						if (position >= 0 && position < ordered_distance_list.size())
						{
							ordered_vertex_list.insert(ordered_vertex_list.begin() + position, neighbours.at(x));
							ordered_distance_list.insert(ordered_distance_list.begin() + position, distances[neighbours.at(x)]);
						}
						else
						{
							ordered_vertex_list.push_back(neighbours.at(x));
							ordered_distance_list.push_back(distances[neighbours.at(x)]);
						}
						break;
					}
				}
			}
		}

		// Fill the open list with the ordered neighbours
		FillOpenList(ordered_vertex_list, ordered_distance_list);

		// Add the shortest item to the closed list and remove it from the open_list
		closed_list.push_back(open_list.at(0).GetVertex());
		open_list.erase(open_list.begin());

		if (closed_list.at(closed_list.size() - 1) == end_node)
			found_end_node = false;
		else
			current_node = closed_list.at(closed_list.size() - 1);
	}

	// Create the final route
	std::vector<std::shared_ptr<Vertex>> route = CreateRoute();
	return route;
}

void Graph::FillOpenList(std::vector<std::shared_ptr<Vertex>> ordered_vertex_list, std::vector<int> ordered_distance_list)
{
	bool empty_list = open_list.size() == 0;
	for (int x = 0; x < ordered_vertex_list.size(); x++)
	{
		// Check if the open list is empty
		if (empty_list)
			open_list.push_back(PositionNode(ordered_vertex_list.at(x), ordered_distance_list.at(x)));
		else
		{
			// Check if the open list already contains the current vertex
			for (int y = 0; y < open_list.size(); y++)
			{
				if (open_list.at(y).GetVertex() == ordered_vertex_list.at(x))
				{
					if (open_list.at(y).GetDistance() > ordered_distance_list.at(x))
						open_list.erase(open_list.begin() + y);
					else
						break;
				}
			}

			// Add the vertex to the open list.
			int position = ordered_distance_list.size() - 1;
			for (int y = ordered_distance_list.size() - 1; y >= 0; y--)
			{
				if (open_list.size() - 1 >= y && open_list.at(y).GetDistance() < ordered_distance_list.at(x))
					position = y;
				else
				{
					if (position >= 0 && position < open_list.size())
						open_list.insert(open_list.begin() + position, PositionNode(ordered_vertex_list.at(x), ordered_distance_list.at(x)));
					else
						open_list.push_back(PositionNode(ordered_vertex_list.at(x), ordered_distance_list.at(x)));
				}
			}
		}
	}
}

int Graph::EstimateDistance(std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node)
{
	int distance = 0;
	for (int x = closed_list.size() - 1; x >= 0; x--)
	{
		std::vector<std::shared_ptr<Edge>> connections = current_node->GetEdges();
		for (int y = 0; y < connections.size(); y++)
		{
			std::vector<std::shared_ptr<Vertex>> positions = connections.at(y)->GetDestinations();
			for (int i = 0; i < positions.size(); i++)
			{
				if (positions.at(i) == closed_list.at(x))
				{
					distance += connections.at(y)->GetWeight();
					break;
				}
			}
		}
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
		std::vector<std::shared_ptr<Edge>> connections = closed_list.at(x)->GetEdges();
		for (int y = 0; y < connections.size(); y++)
		{
			std::vector<std::shared_ptr<Vertex>> positions = connections.at(y)->GetDestinations();
			for (int i = 0; i < positions.size(); i++)
			{
				if (positions.at(i) == closed_list.at(x - 1))
				{
					route.insert(route.begin(), closed_list.at(x - 1));
					break;
				}
			}
		}
	}

	return route;
}

void Graph::MoveHare(std::shared_ptr<Hare> hare)
{
	int posHare;
	do posHare = Utils::RandomNumber(positions.size() - 1);
	while (positions.at(posHare) == hare->GetVertex());

	positions.at(posHare)->SetHare(hare);
	hare->SetVertex(positions.at(posHare));

	//Start over, clear closed and open list
	closed_list.clear();
	open_list.clear();
	distances.clear();
}

std::vector<std::shared_ptr<Vertex>> Graph::getPositions()
{
	return positions;
}

std::vector<std::shared_ptr<Edge>> Graph::getEdges()
{
	return edges;
}