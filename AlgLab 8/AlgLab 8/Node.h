#pragma once

class Node
{
public:
	Node(int num, int cost);
	~Node();
	Node(const Node& o);
	bool operator == (const Node& o);
	int getNumber();
	int getCost();
	void setNumber(int newNum);
	void setCost(int newCost);
private:
	int number;
	int cost;
};

