#include "Graph.h"
#include <vector>
#include <iostream>

Graph::Graph() {};

Graph::Graph(std::list<Node> nodes, std::list<Arc> arcs) {
	this->nodes = nodes;
	this->arcs = arcs;
}

Graph::~Graph() {};

Graph::Graph(const Graph& o) {
	this->nodes = o.nodes;
	this->arcs = o.arcs;
}


std::list<Arc> Graph::getArcs() {
	return this->arcs;
}

std::vector<int> Graph::depthTraversy(std::vector<std::vector<int>> adjMatrix)
{
	std::stack<int> foundNodes;
	std::vector<int> visited;
	int iter = 1;
	int depth = 0;
	do {
		visited.push_back(iter);
		int stackSize = foundNodes.size();
		std::cout << '\n' <<"Visited node: " << iter << '\n';
		for (int i = adjMatrix.size() - 1; i >= 0; --i) {
			if (adjMatrix[i][iter - 1] == 1) {
				foundNodes.push(i + 1);
				for (int j = 0; j < visited.size(); ++j) {
					if ((i + 1) == visited[j]) {
						foundNodes.pop();
					}
				}
				std::cout << '\n' << "Found arx to: " << i + 1 << '\n';
			}

		}
		iter = foundNodes.top();
		foundNodes.pop();
		std::cout << '\n' << "Going to: " << iter  << '\n';
	} while (!foundNodes.empty());
	return visited;
}

void Graph::findCycle() {
	bool flag = false;
	for (auto node : this->nodes) {
		flag = false;
		for (auto arc : this->arcs) {
			if (arc.getFromNode()->getNumber() == node.getNumber()) {
				flag = true;
			}
			if (arc.getToNode()->getNumber() == node.getNumber() && flag) {
				std::cout << "\nCycle found\n";
				return;
			}
		}
	}
	std::cout << "\nCycle not found\n";
}



std::list<Node> Graph::getNodes() {
	return this->nodes;
}

std::vector<std::vector<int>> Graph::buildAdjMatrix() {
	int nodesSize = this->nodes.size();
	std::vector<std::vector<int>> matrix(nodesSize, std::vector<int>(nodesSize));
	for (int i = 0; i < nodesSize; ++i) {
		for (int j = 0; j < nodesSize; ++j) {
			matrix[i][j] = 0;
		}
	}
	for (Arc a : arcs) {
		matrix[(*a.getFromNode()).getNumber() - 1][(*a.getToNode()).getNumber() - 1] = 1;
		matrix[(*a.getToNode()).getNumber() - 1][(*a.getFromNode()).getNumber() - 1] = 1;
	}
	return matrix;
}


void Graph::addNode(Node node) {
	if (!nodes.empty()) {
		node.setNumber(this->nodes.back().getNumber() + 1);
	}
	else {
		node.setNumber(1);
	}
	this->nodes.push_back(node);
}

void Graph::removeNode(int number) {
	for (std::list<Node>::iterator it = nodes.begin(); it != nodes.end();) {
		if ((*it).getNumber() == number) {
			it = nodes.erase(it);
			removeArxToNode(number);
		}
		else {
			++it;
		}
	}
}

void Graph::removeArxToNode(int number){
	auto prev = arcs.begin();
	for (std::list<Arc>::iterator ait = arcs.begin(); ait != arcs.end();) {
		if (((*ait).getFromNode()->getNumber()) == number || ((*ait).getToNode()->getNumber()) == number) {
			removeArc(*ait);
			ait = prev;
		}
		else {
			prev = ait;
			++ait;
		}

	}
}

bool compareNodes(Node val,Node node) {
	return (val == node);
}

void Graph::addArc(Arc arc) {
	this->arcs.push_back(arc);
}

void Graph::removeArc(const Arc& arc) {
	for (std::list<Arc>::iterator it = arcs.begin(); it != arcs.end();) {
		if (*it == arc) {
			it = arcs.erase(it);
		}
		else {
			++it;
		}
	}
}

void Graph::printAsAdjacencyMatrix() {
	int nodesSize = this->nodes.size();
	std::vector<std::vector<int>> matrix(nodesSize, std::vector<int>(nodesSize));
	for (int i = 0; i < nodesSize; ++i) {
		for (int j = 0; j < nodesSize; ++j) {
			matrix[i][j] = 0;
		}
	}
	for (Arc a : arcs) {
		matrix[(*a.getFromNode()).getNumber() - 1][(*a.getToNode()).getNumber() - 1] = 1;
		matrix[(*a.getToNode()).getNumber() - 1][(*a.getFromNode()).getNumber() - 1] = 1;
	}
	for (int i = 0; i < nodesSize; ++i) {
		for (int j = 0; j < nodesSize; ++j) {
			std::cout << ' ' << matrix[i][j];
		}
		std::cout << '\n';
	}
}

void Graph::printAsIncidenceMatrix() {
	int nodesNum = this->nodes.size();
	int arcsNum = this->arcs.size();
	std::vector<std::vector<int>> matrix(nodesNum, std::vector<int>(arcsNum));
	for (int i = 0; i < nodesNum; ++i) {
		for (int j = 0; j < arcsNum; ++j) {
			matrix[i][j] = 0;
		}
	}
	int iter = 0;
	for (Arc a : arcs) {
			matrix[a.getToNode()->getNumber() - 1][iter] = 1;
			matrix[a.getFromNode()->getNumber() - 1][iter] = 1;
			++iter;
	}
	for (int i = 0; i < nodesNum; ++i) {
		for (int j = 0; j < arcsNum; ++j) {
			std::cout << ' ' << matrix[i][j];
		}
		std::cout << '\n';
	}
}

void Graph::printAsAdjacencyList() {
	std::list<Node> otherSideOfArc;
	for (Node n : nodes) {
		otherSideOfArc.clear();
		for (Arc a : arcs) {
			if ((*a.getFromNode()).getNumber() == n.getNumber()) {
				otherSideOfArc.push_back(*a.getToNode());
			}
			else if ((*a.getToNode()).getNumber() == n.getNumber()) {
				otherSideOfArc.push_back(*a.getFromNode());
			}
		}
		std::cout << "Node " << n.getNumber() << " is adjacent to nodes: ";
		for (Node node : otherSideOfArc) {
			std::cout << node.getNumber() << ' ';
		}
		std::cout << '\n';
	}
}

void Graph::printAsArcList() {
	for (Arc a : arcs) {
		std::cout << '[' << (*a.getFromNode()).getNumber() << ", " << (*a.getToNode()).getNumber() << ']' << '\n';
		std::cout << '[' << (*a.getToNode()).getNumber() << ", " << (*a.getFromNode()).getNumber() << ']' << '\n';
	}
}
