#include "Node.h"

Node::Node(int num, int cost) {
	this->number = num;
	this->cost = cost;
}

Node::~Node() {};

Node::Node(const Node& o) {
	this->number = o.number;
	this->cost = o.cost;
}

bool Node::operator == (const Node& o) {
	return(this->number == o.number && this->cost == o.cost);
}

int Node::getNumber(){
	return this->number;
}

int Node::getCost() {
	return this->cost;
}

void Node::setNumber(int num) {
	this->number = num;
}

void Node::setCost(int cost) {
	this->cost = cost;
}
