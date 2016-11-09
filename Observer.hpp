#define __OBSERVER_H__

#include<vector>
#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////
class Observer
{
public:
	Observer(string,bool);
	~Observer() {};
	void setChanged(bool _flag);
	bool getChanged();
	void update();
	bool operator==(Observer& _obs);
	string getName() { return name; }
private:
	string name;
	bool changed = false;
};

Observer::Observer(string _name = "Tom",bool _changed = false)
{
	name = _name;
	changed = _changed;
}
void Observer::setChanged(bool _flag)
{
	changed = _flag;
}
bool Observer::getChanged()
{
	return changed;
}
void Observer::update()
{
	cout << name << ":" 
		<< "Message is received!" 
		<< '\n';
}
bool Observer::operator==(Observer& _obs)
{
	if (name == _obs.name && changed == _obs.changed)
		return true;
	else return false;
}

///////////////////////////////////////////////////////////////////
class Observable
{
private:
	vector<Observer> vec;
	bool changed;
public:
	Observable(bool);
	~Observable() {}
	void addObserver(Observer _obs);
	void deleteObserver(Observer _obs);
	void deleteObserver(string& _name);
	void notifyObservers();
	void change();
};

Observable::Observable(bool _flag = false)
{
	changed = _flag;
}
void Observable::addObserver(Observer _obs)
{
	if (vec.size() != 0) 
	{
		for (vector<Observer>::iterator it = vec.begin();it != vec.end();it++)
		{
			if (*it == _obs)
				return;
		}
		vec.push_back(_obs);
	}
	else
		vec.push_back(_obs);
}

void Observable::deleteObserver(Observer _obs)
{
	for (vector<Observer>::iterator it = vec.begin();it != vec.end();it++)
	{
		if (*it == _obs)
		{
			it = vec.erase(it);
			break;
		}
	}
}
void Observable::deleteObserver(string& _name)
{
	for (vector<Observer>::iterator it = vec.begin();it != vec.end();it++)
	{
		if (it->getName() == _name)
		{
			it = vec.erase(it);
			break;
		}
	}
}

void Observable::notifyObservers()
{
	for (vector<Observer>::iterator it = vec.begin();it != vec.end();it++)
	{
		it->update();
	}
}
void Observable::change()
{
	changed = true;
	notifyObservers();
	changed = false;
}

////////////////////////////////////////////////////////////////////////
class AnimalFather
{
private:
	string classname;
public:
	AnimalFather()
	{
		classname = "AnimalFather";
		cout << classname << " " << "Object Created!" << endl;		
	}
	~AnimalFather() {}
	virtual void Move()
	{
		cout << classname << "Move" << endl;
	}
	void sex()
	{
		cout << classname << " " << "sex" << endl;
	}

};

class Animal:public AnimalFather
{
public: 
	Animal() 
	{
		classname = "Animal";
		cout << classname << " " << "Object" << "Created!" << endl;
	}
	~Animal() {}
	void Eat() { cout << classname << "Eat" << endl; };
	void Cry() { cout << classname << "Cry" << endl; };
	virtual void Move()
	{
		cout << classname << " " << "Move" << endl;
	}
	virtual void Birth()
	{
		cout << classname << " " << "Birth" << endl;
	}
private:
	string classname;
};


class Cat :public Animal
{
public:
	Cat()
	{
		classname = "Cat";
		cout << classname << " " << "Object" << "Created!" << endl;
	}
	~Cat() {}
	void Eat()
	{
		cout << classname << " " << "Eat" << endl;
	}
	void Move()
	{
		cout << classname << " " << "Move" << endl;
	}
	void Die()
	{
		cout << classname << " " << "Die" << endl;
	}
private:
	string classname;
};