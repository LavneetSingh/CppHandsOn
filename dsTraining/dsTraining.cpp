// dsTraining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;
typedef unsigned int uint;
struct s {
	int i;
	float j;
};

int DoComparison(const void* ob1, const void* ob2)
{
	s* s1 = (s*)ob1;
	s* s2 = (s*)ob2;

	if (s1->i == s2->i)
		return 0;
	else if (s1->i < s2->i)
		return -1;
	else if (s1->i > s2->i)
		return 1;
}

int DoComparison2(const void* ob1, const void* ob2)
{
	s* s1 = (s*)ob1;
	int i = (int)ob2;

	if (s1->i == i)
		return 0;
	else if (s1->i < i)
		return -1;
	else if (s1->i > i)
		return 1;
}

void DisplayItem(const void* ob)
{
	s* sp = (s*)ob;
	cout << sp->i << " " << sp->j << endl;
}


void learnCallback()
{
	comparer = DoComparison2;
	display = DisplayItem;

	s s1;
	s s2;
	s1.i = 10;
	s1.j = 11.1;

	s2.i = 20;
	s2.j = 21.1;
	InsertAtEnd(reinterpret_cast<void*>(&s1));
	InsertAtEnd(reinterpret_cast<void*>(&s2));
	
	s s3;
	s3.i = 15;
	s3.j = 15.5;
	int j = 20;
	InsertBefore(reinterpret_cast<void*>(&s3), reinterpret_cast<void*>(&j));


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

struct Student {
	uint id;
	float cpi;
	char* name;
};
void ReadStudentsData();
int main()
{
	ReadStudentsData();
	return 0;
}
void ReadStudentsData()
{
	char data[100];
	char tab;
	ifstream db("Students.txt", ios::in);
	if (db.is_open()) {
		while (!db.eof()) {
			Student* s = new Student;
			db >> s->id >> s->cpi;
			db.get(tab);
			db.getline(data, 100);
			s->name = new char[strlen(data) + 1];
			strcpy_s(s->name, strlen(data)+1, data);
			cout <<s->id << " " << s->name << " " << s->cpi << endl;
		}
	}

}
