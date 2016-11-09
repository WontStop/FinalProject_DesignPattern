#define __COMPOSITE_H__

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Composite
{
public:
	Composite(string& _name,bool _isObject):name(_name) {}
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
	virtual bool getObject()
	{
		return isObject;
	}
private:
	string name;
	int size;
	bool isObject;
};

class Object:public Composite
{
public:
	Object(string& _name) :Composite(_name,true),name(_name) { 
		size = 1; 
		isObject = true;
	}
	~Object() {}
	string getName() { 
		return name; 
	}
	int getSize() { 
		return size; 
	}
	void printList(string _front) {
		cout << "Error:" << "Object can't print the list" << endl;
		return;
	}
	void add(Composite*_comp)
	{
		cout << "Error:" << "Object can't contain other composite! " << endl;
		return;
	}
	bool getObject()
	{
		return isObject;
	}

private:
	string name;
	int size;
	bool isObject;
};

class Container :public Composite
{
public:
	Container(string& _name) :Composite(_name,false), name(_name) {
	size = 0;
	isObject = false;
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
	void printList(string _front = "")
	{
		for (vector<Composite*>::iterator it = vec.begin();it != vec.end();it++)
		{
			string name = (*it)->getName();
			cout << _front
				<< "/" << name << endl;
			string _nextfront = _front + "/" + name;
			if (!(*it)->getObject())
			{
				(*it)->printList(_nextfront);
			}
		}
	}
	void add(Composite* _comp)
	{
		vec.push_back(_comp);
		size++;
	}
	bool getObject()
	{
		return isObject;
	}
private:
	string name;
	int size;
	bool isObject;
	vector<Composite*> vec;
};