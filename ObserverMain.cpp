#include<iostream>
#include<string>
#include"Observer.hpp"
#include"Composite.hpp"
#include"UndoRedo.hpp"

using namespace std;

void main()
{
	char flag = '5';

	string name = "Observable";
	Observer* observer;
	Observable* observable = nullptr;
	while (flag != '0')
	{
		void printOrder();
		printOrder();
		cin >> flag;

		switch (flag)
		{
		case '1':
		{
			cin >> name;
			observable = new Observable(name);
			break;
		}
		case '2':
		{
			cin >> name;
			observer = new Observer(name);
			Observer temp = *observer;
			observable->addObserver(temp);
			break;
		}
		case '3':
		{
			cin >> name;
			observable->deleteObserver(name);
			break;
		}
		case '4':
		{
			observable->setChanged();
			break;
		}
		case '5':
		{
			if (observable == nullptr)
			{
				cout << "error! observable is null" << endl;
			}
			else
			{
				cout << "*************Observer List(start)************" << endl;
				observable->printObserverList();
				cout << "*************Observer List(over)*************" << endl;
			}
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
	cout << "-------------Observer Pattern--------------" << endl;
	cout << "1. New Observable" << endl;
	cout << "2. Add New Observer" << endl;
	cout << "3. Delete Old Observer" << endl;
	cout << "4. Change the Observable" << endl;
	cout << "5. Print the Observer List" << endl;
	cout << "0. exit undo/redo Pattern" << endl;
	cout << "Please input the order..." << endl;
	cout << "-------------Observer Pattern--------------" << endl;
}