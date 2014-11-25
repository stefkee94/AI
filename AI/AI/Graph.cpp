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
		AddVertex();

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
	int posCow = rand() % positions.size();
	positions.at(posCow)->SetCow(cow);
	cow->SetVertex(positions.at(posCow));
	
	// Add the hare to a vertex
	int posHare;
	do posHare = rand() % positions.size();
	while (posCow == posHare);
	
	positions.at(posHare)->SetHare(hare);
	hare->SetVertex(positions.at(posHare));
}

void Graph::AddVertex()
{
	positions.push_back(std::make_shared<Vertex>(rand() % 900, rand() % 400));
}

void Graph::AddEdges(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
	std::shared_ptr<Edge> edge = std::make_shared<Edge>(rand() % 100, start, end);
	edges.push_back(edge);
	start->AddObject(edge);
	end->AddObject(edge);
}

void Graph::Search(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node, std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare)
{
	FillOpenList(start_node);

	if (distances.size() > 0)
		FillClosedList(distances, cow, hare);
	// Calculate distance of the node to the end_node
	//CalculateDistance(start_node, end_node);
}

void Graph::FillOpenList(std::shared_ptr<Vertex> current_node)
{
	//First add current node to Closed list
	if (closed_list.empty())
		closed_list.push_back(current_node);
	bool is_same = false;
	for (int c = 0; c < closed_list.size(); c++)
	{
		if (closed_list.at(c)->getWeight() != current_node->getWeight())
			continue;
		else
		{
			is_same = true;
			break;
		}
	}

	if (!is_same)
		closed_list.push_back(current_node);

	std::vector<std::shared_ptr<Edge>> edges = current_node->GetEdges();

	for (int i = 0; i < edges.size(); i++)
	{
		std::shared_ptr<Edge> edge = edges.at(i);
		std::vector<std::shared_ptr<Vertex>> positions = edge->GetDestinations();

		// Add all the positions to the closed list, which are not in the closed list.
		for (int x = 0; x < positions.size(); x++)
		{
			if (positions.at(x) != current_node)
			{
				if (std::find(closed_list.begin(), closed_list.end(), positions.at(x)) == closed_list.end())
				{
					// Check if the item is in the openlist
					if (std::find(open_list.begin(), open_list.end(), positions.at(x)) != open_list.end())
					{
						// TODO: Calculate distance to the end point, if it is shorter then the existing position remove the position
						//		 And add this as the new position.
						//
						//open_list.push_back(positions.at(x));
						/*for (int c = 0; c < closed_list.size() - 1; c++)
						{
							if (closed_list[c]->getWeight() == )
						}*/
						CalculateDistance(closed_list.at(closed_list.size()-1), open_list.at(x), edges.at(x));
					}
					else
					{
						open_list.push_back(positions.at(x));
					}
				}
			}
		}
	}
}

void Graph::FillClosedList(std::vector<int> lowest_distance, std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare)
{
	for (int openl = 0; openl < open_list.size(); openl++)
	{
		std::vector<std::shared_ptr<Edge>> tmp_edges = open_list[openl]->GetEdges();
		for (int w = 0; w < tmp_edges.size(); w++)
		{
			if (tmp_edges[w]->GetWeight() == lowest_distance.at(0))
			{
				std::shared_ptr<Vertex> to_closed_list = open_list.at(openl);
				closed_list.push_back(to_closed_list);
				open_list.erase(open_list.begin() + openl);
				to_closed_list->SetCow(cow);
				cow->SetVertex(closed_list.at(closed_list.size()-1));
				return;
			}
		}
	}
}

void Graph::CalculateDistance(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node, std::shared_ptr<Edge> edge)
{
	int checkClosedList = edge->GetDestinations()[0]->getWeight();
	// NOT WORKING YET, previous path is taken as well
	for (int c = 0; c < closed_list.size(); c++)
	{
		if (checkClosedList == closed_list[c]->getWeight())
			return;
	}
	
	if (distances.empty())
		distances.push_back(edge->GetWeight());
	else
	{
		for (int d = 0; d < distances.size(); d++)
		{
			if (distances.at(d) > edge->GetWeight())
			{
				distances.erase(distances.begin() + d);
				distances.push_back(edge->GetWeight());
			}
		}
	}
}

void Graph::MoveHare(std::shared_ptr<Hare> hare, int prev_position)
{
	int posHare;
	do posHare = rand() % positions.size();
	while (posHare == prev_position);

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