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
		while (CurEdge->To != End) // CurEdge->To - �������, ���������� �� ������� ������� �� ���������� ����
		{ 
			CurGraphNode = AllNodes.ShowHead();
			minDistToVert = INT_MAX;
			while (CurGraphNode != nullptr)
			{ // ������� ������� � ����������� ����������� ����� ���� ���������
				MinEdgeFromVert = AllEdges.MinEdgeFromVertex(CurGraphNode->vertex); // ������� ������������ � ����������� ����������� ������� �� ������
				if (MinEdgeFromVert != nullptr) // ���� �� ���� ������� ����� ������ ��������� ������� �� ���������� ���������� �������
				{
					if (MinEdgeFromVert->weight + CurGraphNode->minDistTo < minDistToVert)
					{
						CurEdge = MinEdgeFromVert; // ���������� ���������� ���� �� ��������� � ���������� ����� ������� �� ����� �������
						minDistToVert = MinEdgeFromVert->weight + CurGraphNode->minDistTo;  // ���������� �� ����������� ��������� ������� �� ���������� ����� + �� ���� ������� �� ����� �������
					}
					
				}
				CurGraphNode = CurGraphNode->next;
			}
			Node* previousNode = AllNodes.Find(CurEdge->from); // ����������� ������� �� ������� ������� ����������� ����������
			AllNodes.push_back(CurEdge->To, previousNode->minDistTo + CurEdge->weight); // ��������� ������� � ������ ���������
			minDistToVert = previousNode->minDistTo + CurEdge->weight;
			AllEdges.VertexProcessed(CurEdge->To); // �������� ������� ��� ��� ����������� ���������� �� ��� ��� �������
		}
		return minDistToVert;
	}
	
};