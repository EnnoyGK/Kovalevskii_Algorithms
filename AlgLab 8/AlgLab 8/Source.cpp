#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
	Node node1(1, 0);
	Node node2(2, 0);
	Node node3(3, 0);
	Node node4(4, 0);
	Node node5(5, 0);

	Arc arc12(&node1, &node2, 0);
	Arc arc23(&node2, &node3, 0);
	Arc arc45(&node4, &node5, 0);
	Arc arc51(&node5, &node1, 0);
	Arc arc14(&node1, &node4, 0);

	Graph graph;
	graph.addNode(node1);
	graph.addNode(node2);
	graph.addNode(node3);
	graph.addNode(node4);
	graph.addNode(node5);

	

	graph.addArc(arc12);
	graph.addArc(arc23);
	graph.addArc(arc45);
	graph.addArc(arc51);
	graph.addArc(arc14);

	graph.removeNode(5);
	graph.removeArc(arc23);

	cout << "\n \n \n" << "WITHOUT NODE 5 AND ARC 2--3" << "\n \n \n";

	cout << "Adjacency List" << '\n';
	graph.printAsAdjacencyList();
	cout << "Adjacency Matrix" << '\n';
	graph.printAsAdjacencyMatrix();
	cout << "Arc List" << '\n';
	graph.printAsArcList();
	cout << "Incidence Matrix" << '\n';
	graph.printAsIncidenceMatrix();

	graph.findCycle();

	graph.addNode(node5);
	graph.addArc(arc45);
	graph.addArc(arc51);
	graph.addArc(arc23);
	

	cout << "\n \n \n" << "WITH NODE 5" << "\n \n \n";

	cout << "Adjacency List" << '\n';
	graph.printAsAdjacencyList();
	cout << "Adjacency Matrix" << '\n';
	graph.printAsAdjacencyMatrix();
	cout << "Arc List" << '\n';
	graph.printAsArcList();
	cout << "Incidence Matrix" << '\n';
	graph.printAsIncidenceMatrix();

	cout << "\n \n \n" << "Traversy" << "\n \n \n";

	vector<vector<int>> adjMatr;
	adjMatr = graph.buildAdjMatrix();
	vector<int> traversy;
	graph.findCycle();
	//traversy = graph.depthTraversy();
	/*cout << "Visited nodes: ";
	for (int i = 0; i < traversy.size(); ++i) {
		cout << traversy[i] << ' ';
	}*/

	return 0;
}
