#include "Arc.h"

Arc::Arc(Node* from, Node* to, int weight) {
	this->fromNode = from;
	this->toNode = to;
	this->weight = weight;
}

Arc::~Arc() {};

Arc::Arc(const Arc& o) {
	this->fromNode = o.fromNode;
	this->toNode = o.toNode;
	this->weight = o.weight;
}

bool Arc::operator == (const Arc& o) { 
	return(this->fromNode == o.fromNode && this->toNode == o.toNode && this->weight == o.weight);
}

int Arc::getWeight() {
	return this->weight;
}

Node* Arc::getFromNode() {
	return this->fromNode;
}

Node* Arc::getToNode() {
	return this->toNode;
}

void Arc::setWeight(int newWeight) {
	this->weight = newWeight;
}

void Arc::setFromNode(Node* newFromNode) {
	this->fromNode = newFromNode;
}

void Arc::setToNode(Node* newToNode) {
	this->toNode = newToNode;
}