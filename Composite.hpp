#define __COMPOSITE_H__

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Composite
{
public:
	Composite(string& _name):name(_name) {}
	~Composite() {}
	virtual string getName() 
	{ 
		return name; 
	}
	virtual int getSize() 
	{ 
		return size; 
	}
	virtual void printList(string _front = "")
	{ 
	}
	virtual void add(Composite* _comp) 
	{
	}
	virtual Composite* searchContainer(string _name) {
		return nullptr;
	}
private:
	string name;
	int size;
};

class Object:public Composite
{
public:
	Object(string& _name) :Composite(_name),name(_name) { 
		size = 1; 
	}
	~Object() {}
	string getName() { 
		return name; 
	}
	int getSize() { 
		return size; 
	}
	void printList(string _front) {
		///////////////////////////////////////////////////////////
		//At the final presentation, Teacher Zongjian He said 
		//Object and Container should have the same interface
		//So I decide to change the current mode...

		//The origin version
		//cout << "Error:" << "Object can't print the list" << endl;
		//return;

		//Current Version
		cout << _front << "/" << getName() << endl;
	}
	void add(Composite*_comp)
	{
		cout << "Error:" << "Object can't contain other composite! " << endl;
		return;
	}
	Composite* searchContainer(string _name) {
		return nullptr;
	}
private:
	string name;
	int size;
};

class Container :public Composite
{
public:
	Container(string& _name) :Composite(_name), name(_name) {
	size = 0;
	}
	~Container() {}
	string getName() 
	{
		return name;
	}
	int getSize()
	{
		return size;
	}
	void add(Composite* _comp)
	{
		vec.push_back(_comp);
		size++;
	}
	void printList(string _front = "")
	{
		cout << _front << "/" << getName() << endl;
		for (vector<Composite*>::iterator it = vec.begin();it != vec.end();it++)
		{
			string _nextfront = _front + "/" + name;
			(*it)->printList(_nextfront);
			//if (!(*it)->getObject())
			//{
			//	(*it)->printList(_nextfront);
			//}
		}
	}
	Composite* searchContainer(string _name)
	{
		if (this->getName() == _name)
			return this;
		for (vector<Composite*>::iterator it = vec.begin();it != vec.end();it++)
		{
			if ((*it)->getName() == _name)
				return (*it);
			else
			{
				Composite* result = (*it)->searchContainer(_name);
				if (result != nullptr)
					return result;
			}
		}
		return nullptr;
	}
private:
	string name;
	int size;
	vector<Composite*> vec;
};