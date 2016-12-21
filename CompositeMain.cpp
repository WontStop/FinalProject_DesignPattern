#include<iostream>
#include<string>
#include"Observer.hpp"
#include"Composite.hpp"
#include"UndoRedo.hpp"

using namespace std;

void main()
{
	char flag = '5';
	string name = "root";
	Composite* composite;
	Object* object;
	Container* root = new Container(name);
	Container* container;
	container = root;
	while (flag != '0')
	{
		void printOrder();
		printOrder();
		cin >> flag;
		switch (flag)
		{
		case '1':
		{
			string name = "";
			cin >> name;
			while (name == "")
			{
				cout << "Please input the object name:" << endl;
				cin >> name;
			}
			composite = new Object(name);
			container->add(composite);
			break;
		}
		case '2':
		{
			string name = "";
			cin >> name;
			while (name == "")
			{
				cout << "Please input the container name:" << endl;
				cin >> name;
			}
			composite = new Container(name);
			container->add(composite);
			break;
		}
		case '3':
		{
			cout << "***********Composite List (start)***********" << endl;
			container->printList();
			cout << "***********Composite List (over)************" << endl;
			break;
		}
		case '4':
		{
			string name = "";
			cin >> name;
			while (name == "")
			{
				cout << "please input the container name:" << endl;
				cin >> name;
			}
			Composite* result;
			result = root->searchContainer(name);
			if (result != nullptr)
			{
				container = (Container*)result;
				cout << "The current container is " << container->getName() << endl;
			}
			else
				cout << "Container " << name << " not found!" << endl;

		}
		default:
			break;
		}
	}
}

void printOrder()
{
	cout << endl;
	cout << "-------------Composite Pattern--------------" << endl;
	cout << "1. add a new Object" << endl;
	cout << "2. add a new Container" << endl;
	cout << "3. print the Objects and Container" << endl;
	cout << "4. change to the specific Container" << endl;
	cout << "0. exit Composite Pattern" << endl;
	cout << "Please input the order..." << endl;
	cout << "-------------Composite Pattern--------------" << endl;
}