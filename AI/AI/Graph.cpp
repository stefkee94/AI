#include "Graph.h"

Graph::Graph()
{
	Init();
}

Graph::~Graph()
{
}

void Graph::Init()
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
}

void Graph::AddVertex()
{
	//positions.push_back(std::shared_ptr<Vertex>(new Vertex(rand() % 400, rand() % 400)));
	positions.push_back(Vertex(rand() % 900, rand() % 400));
}

void Graph::AddEdges(Vertex start, Vertex end)
{
	edges.push_back(Edge(rand() % 100, start, end));
}

void Graph::Search(std::shared_ptr<Vertex> start_node, std::shared_ptr<Vertex> current_node, std::shared_ptr<Vertex> end_node)
{
	// Search the closest 
}

void Graph::FillOpenList()
{
	// Fill the open list with all the nodes connected to the currentnode.
}

std::vector<Vertex> Graph::getPositions()
{
	return positions;
}

std::vector<Edge> Graph::getEdges()
{
	return edges;
}