#include <iostream>
#include <fstream>
#include <string>
#include"dijkstra.h"
using namespace std;

int main()
{
    dijkstra a;
	string Begin, End;
	cin >> Begin >> End;
	ofstream out;
	out.open("graph.txt");
	if (out.is_open())
	{
		/*out << "A;B;10;N/A";
		out << endl;
		out << "B;D;50;N/A";
		out << endl;
		out << "A;C;100;N/A";
		out << endl;
		out << "E;D;20;N/A";
		out << endl;
		out << "E;C;60;N/A";
		out << endl;
		out << "D;C;7;N/A";
		out << endl;
		out << "A;E;30;N/A";*/
		///////////////////////
		/////////////////////////
		out << "Russia;B;5;10";
		out << endl;
		out << "A;B;3;5";
		out << endl;
		out << "A;C;4;6";
		out << endl;
		out << "B;D;15;6";
		out << endl;
		out << "C;D;2;6";
	}
	out.close();
	int result = a.alghoritm("graph.txt",Begin,End);
	cout << result << endl;
	return 0;
	
}