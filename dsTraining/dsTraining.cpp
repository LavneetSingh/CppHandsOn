// dsTraining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	struct s {
		int i;
		float j;
	};
	s s1;
	s s2;
	s1.i = 10;
	s1.j = 11.1;

	s2.i = 20;
	s2.j = 21.1;
	InsertAtEnd(reinterpret_cast<void*>(&s1));
	InsertAtEnd(reinterpret_cast<void*>(&s2));
	
	auto a = new s;
	auto b = new s;
	a->i = 30;
	a->j = 31.1;
	b->i = 40;
	b->j = 40.1;
	InsertAtEnd(reinterpret_cast<void*>(a));
	InsertAtEnd(reinterpret_cast<void*>(b));


	DisplayList();
	//InsertAtFront(reinterpret_cast<void*>(10));
	//auto a = DeleteNode(13);
	//auto b = DeleteNode(16);

	//FindNode(13) == 1 ? std::cout << "13 present" : std::cout << "13 absent";
	//cout << endl;
	//FindNode(12) == 1 ? std::cout << "12 present" : std::cout << "12 absent";
	//cout << endl;
	DisplayList();

	//InsertAfter(16, 15);
	//InsertBefore(13, 14);
	//FindNode(13) == 1 ? std::cout << "13 present" : std::cout << "13 absent";
	//cout << endl;

	//DisplayList();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
