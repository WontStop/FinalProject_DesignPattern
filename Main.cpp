#include<iostream>
#include<string>
#include"Observer.hpp"
#include"Composite.hpp"

using namespace std;

void main()
{
	
	string a[10] = { "O1","O2","O3","O4","O5","O6","O7","O8","O9","O10" };
	string container[10] = { "C1","C2" ,"C3" ,"C4" ,"C5" ,"C6" ,"C7" ,"C8" ,"C9" ,"C10" };
	Composite* comp;
	Container* cont;
	string contname = "MyContainer";
	Container* root = new Container(contname);

	for (int i = 0;i < 10;i++)
	{
		comp = new Object(a[i]);
		root->add(comp);		
	}
	root->printList();
	
	for (int i = 0;i < 10;i++)
	{
		comp = new Container(container[i]);
		root->add(comp);
		if (i == 0)
		{
			Composite* temp;
			for (int j = 0;j < 10;j++)
			{
				temp = new Object(a[j]);
				comp->add(temp);
			}
		}
		if (i == 5)
		{
			string newname = "LiYongxun";
			Container* cont;
			cont = new Container(newname);
			comp->add(cont);

			Composite* tempo;
			for (int j = 0;j < 10;j++)
			{
				tempo = new Object(a[j]);
				cont->add(tempo);
			}
		}
		if (i == 9)
		{
			string newname = "Huangxiaoming";
			cont = new Container(newname);
			comp->add(cont);

			Composite* tempo;
			for (int j = 0;j < 10;j++)
			{
				tempo = new Object(a[j]);
				cont->add(tempo);
			}			
		}	
	}
	root->printList();
	


	/*
	//测试向量中的迭代器调用父类函数
	AnimalFather* anif = new AnimalFather();
	Animal * ani = new Animal();
	Cat* cat = new Cat();

	anif->Move();
	ani->Move();
	cat->Move();
	cout << endl;
	anif = cat;
	anif->Move();
	cout << '\n';
	vector<AnimalFather> vec;
	vec.push_back(*cat);
	vector<AnimalFather>::iterator it = vec.begin();
	it->Move();
	anif = cat;
	anif->Move();
	anif->Move();
	AnimalFather father = (AnimalFather)*it;
	father.Move();
	vec[0].Move();	
	*/


	/*
	//测试观察者模式
	Observer* obs = new Observer();
	Observable* obsb = new Observable();
	string a[10] = { "P1","P2","P3","P4","P5","P6","P7","P8","P9","P10" };
	for (int i = 0;i < 10;i++) {
		string name = a[i];
		obs = new Observer(name);
		obsb->addObserver(*obs);
	}
	obsb->deleteObserver(*obs);
	obsb->change();
	cout << endl;

	//测试不同数据类型所占内存的大小
	//size of all kinds of basic data;
	short int i = 1024*32;
	short int ii = (1<<15)-1;
	cout << i << " " << ii << endl;
	cout << "Short int " << sizeof(short int) << endl;
	cout << "int:" << sizeof(int) << endl;
	cout << "long int " << sizeof(long int) << endl;
	cout << "long long " << sizeof(long long) << endl;
	cout << "float " << sizeof(float) << endl;
	cout << "double" << sizeof(double) << endl;
	cout << "long double" << sizeof(long double) << endl;

	bool bargin = false;
	//测试类的继承关系
	//Test pointer, virtual function;
	Animal ani;
	Cat cat;
	Animal* pani = NULL;
	pani = &ani;
	Cat* pcat = &cat;
	pani->Eat();
	pani->Cry();
	pani->Move();
	pani->Birth();
	pani->sex();

	pcat->Eat();
	pcat->Cry();
	pcat->Move();
	pcat->Birth();
	pcat->Die();
	pcat->sex();

	pani = &cat;
	pani->Eat();
	pani->Cry();
	pani->Move();
	pani->Birth();
	pani->sex();

	AnimalFather animalfather;
	AnimalFather* panif = &animalfather;
	panif->Move();
	panif->sex();

	panif = &ani;
	panif->Move();
	panif->sex();

	panif = &cat;
	panif->Move();
	panif->sex();
	*/
}