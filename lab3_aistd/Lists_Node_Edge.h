#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class edge
{
public:
	string from;
	string To;
	int weight;
	edge* next;
	bool ToVertexProcessed;
	edge()
	{
		from = "";
		To = "";
		weight = 0;
		next = nullptr;
		ToVertexProcessed = false;
	}
};

class edgeList
{
	edge* head;
	edge* tail;
	int Size;
public:
	edgeList()
	{
		tail = head = nullptr;
		Size = 0;
	}
	void push_back(string from,string To, int weight)
	{
		edge* current = new edge();
		current->from = from;
		current->To = To;
		current->weight = weight;
		if (head == nullptr)
		{
			tail = head = current;
			current->next = nullptr;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
		Size++;
	}
	void VertexProcessed(string To)
	{
		edge* current = head;
		for (int i = 0; i < Size; i++)
		{
			if (current->To == To)
			{
				current->ToVertexProcessed = true;
			}
			current = current->next;
		}
	}
	edge* MinEdgeFromVertex(string from)
	{
		edge* current = head;
		edge* SearchMinTo = nullptr;
		int min = INT_MAX;
		for (int i = 0; i < Size; i++)
		{
			if (current->from == from)
			{
				if (current->weight < min && current->ToVertexProcessed == false)
				{
					min = current->weight;
					SearchMinTo = current;
				}
			}
			current = current->next;
		}
		return SearchMinTo;
	}
	~edgeList()
	{
		edge *current = head;
		while (current != tail)
		{
			edge* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
		Size = 0;
	}
};

class Node
{
public:
	string vertex;
	int minDistTo;
	Node* next;
	Node()
	{
		vertex = "";
		minDistTo = 0;
		next = nullptr;
	}
};

class NodeList
{
	Node* head;
	Node* tail;
public:
	NodeList()
	{
		tail = head = nullptr;
	}
	void push_back(string city, int min)
	{
		Node* current = new Node();
		if (head == nullptr)
		{
			tail = head = current;
			current->vertex = city;
			current->minDistTo = min;
		}
		else
		{
			tail->next = current;
			tail = current;
			current->vertex = city;
			current->minDistTo = min;
		}
	}
	Node* ShowHead()
	{
		return head;
	}
	Node* Find(string From)
	{
		Node* current = head;
		while (current->vertex != From)
		{
			current = current->next;
		}
		return current;
	}
	~NodeList()
	{
		Node* current = head;
		while (current != tail)
		{
			Node* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
	}
};