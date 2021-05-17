#pragma once
#include <iostream>
#include <string>
#include"Lists_Node_Edge.h"

#include <fstream>
using namespace std;


class dijkstra
{
public:
	int alghoritm(string graph, string Begin, string End)
	{

		edgeList AllEdges;
		ifstream in(graph);
		int weight1, weight2;
		string LineFromFile;
		if (in.is_open())
		{
			while (getline(in, LineFromFile))
			{
				int j = 0;
				string information[4];
				for (int i = 0; i < LineFromFile.size(); i++)
				{
					if (LineFromFile[i] == ' ' || LineFromFile[i] == ';')
					{
						i++;
						j++;
					}
		
					information[j] += LineFromFile[i];
				}
				if (information[2] == "N/A")
				{
					weight1 = INT_MAX;
				}
				else
				{
					weight1 = stoi(information[2]);
				}
				if (information[3] == "N/A")
				{
					weight2 = INT_MAX;
				}
				else
				{
					weight2 = stoi(information[3]);
				}
				AllEdges.push_back(information[0], information[1], weight1);
				AllEdges.push_back(information[1], information[0], weight2);
			}
		}
		in.close();
		edge *MinEdgeFromVert;
		Node* CurGraphNode;
		NodeList AllNodes;
		AllNodes.push_back(Begin, 0);
		edge *CurEdge = AllEdges.MinEdgeFromVertex(Begin);
		int minDistToVert = CurEdge->weight;
		while (CurEdge->To != End) // CurEdge->To - вершина, расстояние до которой найдено на предыдущем шаге
		{ 
			CurGraphNode = AllNodes.ShowHead();
			minDistToVert = INT_MAX;
			while (CurGraphNode != nullptr)
			{ // находит вершину с минимальным расстоянием среди всех остальных
				MinEdgeFromVert = AllEdges.MinEdgeFromVertex(CurGraphNode->vertex); // находит неотмеченную с минимальным расстоянием вершину от данной
				if (MinEdgeFromVert != nullptr) // если от этой вершины ведут только найденные вершины то пропускаем внутреннее условие
				{
					if (MinEdgeFromVert->weight + CurGraphNode->minDistTo < minDistToVert)
					{
						CurEdge = MinEdgeFromVert; // запоминает кратчайшую дугу от найденной в предыдущих шагах вершины до новой вершины
						minDistToVert = MinEdgeFromVert->weight + CurGraphNode->minDistTo;  // расстояние до проверенной найденной вершины на предыдущих шагах + от этой вершины до новой вершины
					}
					
				}
				CurGraphNode = CurGraphNode->next;
			}
			Node* previousNode = AllNodes.Find(CurEdge->from); // проверенная вершина от которой найдено минимальное расстояние
			AllNodes.push_back(CurEdge->To, previousNode->minDistTo + CurEdge->weight); // добавляем вершину в список найденных
			minDistToVert = previousNode->minDistTo + CurEdge->weight;
			AllEdges.VertexProcessed(CurEdge->To); // отмечаем вершину так как минимальное расстояние до нее уже найдено
		}
		return minDistToVert;
	}
	
};