#pragma once
#include<list>
#include<stack>
#include<vector>
#include"Arc.h"
class Graph
{
public:
	Graph();
	Graph(std::list<Node> nodes, std::list<Arc> arcs);
	~Graph();
	Graph(const Graph& o);
	std::list<Node> getNodes();
	std::list<Arc> getArcs();
	std::vector<int> depthTraversy(std::vector<std::vector<int>> adjMatrix);
	std::vector<std::vector<int>> buildAdjMatrix();
	void findCycle();
	void addNode(Node node);
	void removeNode(int number);
	void removeArxToNode(int number);
	void addArc(Arc arc);
	void removeArc(const Arc& arc);
	void printAsAdjacencyMatrix();
	void printAsIncidenceMatrix();
	void printAsAdjacencyList();
	void printAsArcList();
private:
	std::list<Node> nodes;
	std::list<Arc> arcs;
};

