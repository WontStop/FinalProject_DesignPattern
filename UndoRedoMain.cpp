#include<iostream>
#include<string>
#include"Observer.hpp"
#include"Composite.hpp"
#include"UndoRedo.hpp"

using namespace std;

void main()
{
	char flag = '5';
	UndoableEdit* edit;
	CompoundEdit* compound;
	UndoManager* manager = new UndoManager("Manager");
	while (flag != '0')
	{
		void printOrder();
		printOrder();
		cin >> flag;
		string newname;
		switch (flag)
		{
		case '1':
		{
			cout << "Please input action name:" << endl;
			cin >> newname;
			edit = new UndoableEdit(newname);
			manager->addEdit(edit);
			break;
		}
		case '2':
		{manager->undo();
		break;
		}
		case '3': {
			manager->redo();
			break;}
		case '4':
		{
			manager->printList();
			break;
		}
		case '0':
		{
			break;
		}
		default:
			break;
		}
	}
}

void printOrder()
{
	cout << endl;
	cout << "-------------Undo/Redo Pattern--------------" << endl;
	cout << "1. add a new action" << endl;
	cout << "2. undo the current action" << endl;
	cout << "3. redo the last action" << endl;
	cout << "4. print the list of all actions" << endl;
	cout << "0. exit undo/redo Pattern" << endl;
	cout << "Please input the order..." << endl;
	cout << "-------------Undo/Redo Pattern--------------" << endl;
}