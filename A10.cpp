// A10.cpp : Defines the entry point for the console application.
//
#include "ToDo.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{

	cout << "Welcome to the Anti-procrastination Prioritizer:\n";
	cout << "Enter a task you must do, specify a priority of < 1 to stop." << endl;

	ToDo todo;
	todo = ToDo();

	vector<ToDo> ToDoList (0);

	do {
		
		cout << "What is the task?";
		cin >> todo.task;

		cout << "What is the priority of this task?";
		cin >> todo.priority;

		if (todo.priority > 0) {
			ToDoList.push_back(todo);
		}

	} while (todo.priority > 0);

	cout << "\nThis is your tasklist. Tasks are listed in order of priority starting with the most important\n";

	int swaps;
	do {
		for (int i = 0, int j = 1; j < ToDoList.size(); i++, j++) {
			int first = ToDoList[i].priority;
			int second = ToDoList[j].priority;
			if (first > second) {
				ToDo firstToDo = ToDoList[i];
				ToDo secondToDo = ToDoList[j];
				ToDoList[j] = firstToDo;
				ToDoList[i] = secondToDo;
				swaps++;
			}
		}
		
	} while (swaps != 0);

	for (int i = 0; i < ToDoList.size(); i++) {
		cout << setw(6) << left << ToDoList[i].priority << setw(8) << ToDoList[i].task << endl;
	}
	
	system("PAUSE");
    return 0;
}

