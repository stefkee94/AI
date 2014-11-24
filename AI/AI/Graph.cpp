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

void Graph::Search(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> end_node, std::shared_ptr<Cow> cow, std::shared_ptr<Hare> hare)
{
	FillOpenList(current_node);

	// Calculate distance of the node to the end_node
	CalculateDistance(current_node, end_node);
}

void Graph::FillOpenList(std::shared_ptr<Vertex> current_node)
{
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

void Graph::CalculateDistance(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> end_node)
{

}

std::vector<std::shared_ptr<Vertex>> Graph::getPositions()
{
	return positions;
}

std::vector<std::shared_ptr<Edge>> Graph::getEdges()
{
	return edges;
}