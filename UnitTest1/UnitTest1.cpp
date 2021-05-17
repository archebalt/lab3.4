#include "pch.h"
#include "CppUnitTest.h"
#include"..\lab3_aistd\dijkstra.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Dijkstra)
		{
			dijkstra a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "A;B;10;N/A";
				out << endl;
				out << "B;D;50;N/A";
				out << endl;
				out << "A;C;100;N/A";
				out << endl;
				out << "E;D;20;N/A";
				out << endl;
				out << "E;C;60;N/A";
				out << endl;
				out << "D;C;10;N/A";
				out << endl;
				out << "A;E;30;N/A";
			}
			out.close();
			int result = a.alghoritm("graph.txt", "A", "C");
			int sup = 60;
			Assert::AreEqual(result, sup);
		}
		TEST_METHOD(Dijkstra2)
		{

			dijkstra a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "A;B;10;20";
				out << endl;
				out << "B;D;50;30";
				out << endl;
			}
			out.close();
			int result = a.alghoritm("graph.txt", "D", "A");
			int sup = 50;
			Assert::AreEqual(result, sup);
		}
		TEST_METHOD(Dijkstra3)
		{
			dijkstra a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
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
			int result = a.alghoritm("graph.txt", "Russia", "D");
			int sup = 16;
			Assert::AreEqual(result, sup);
		}
	};
}
