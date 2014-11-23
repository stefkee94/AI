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
			AddEdges(positions[j], positions[j+2]);
		if (j == 1)
			AddEdges(positions[j], positions[j+2]);
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
	//positions.push_back(std::shared_ptr<Vertex>(new Vertex(rand() % 400, rand() % 400)));
	positions.push_back(std::make_shared<Vertex>(rand() % 900, rand() % 400));
}

void Graph::AddEdges(std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> end)
{
	edges.push_back(std::make_shared<Edge>(rand() % 100, start, end));
}

void Graph::Search(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> end_node)
{
	// Search the closest 
}

void Graph::FillOpenList()
{
	// Fill the open list with all the nodes connected to the currentnode.
}

std::vector<std::shared_ptr<Vertex>> Graph::getPositions()
{
	return positions;
}

std::vector<std::shared_ptr<Edge>> Graph::getEdges()
{
	return edges;
}