#pragma once
#include "Node.h"
class Arc
{
public:
	Arc(Node* from, Node* to, int weight);
	~Arc();
	Arc(const Arc &o);
	bool operator == (const Arc& o);
	Node* getFromNode();
	Node* getToNode();
	int getWeight();
	void setFromNode(Node* newFromNode);
	void setToNode(Node* newToNode);
	void setWeight(int weight);
private:
	Node* fromNode;
	Node* toNode;
	int weight;
};

