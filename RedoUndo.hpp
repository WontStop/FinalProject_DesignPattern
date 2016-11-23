#include<iostream>
#include<vector>
using namespace std;

class UndoableEdit
{
public: 
	UndoableEdit() 
	{

	}
		~UndoableEdit() 
	{ 
		
	}
	bool undo()
	{

	}
	bool canUndo()
	{

	}
	bool redo()
	{

	}
	bool canRedo()
	{

	}
	void addEdit()
	{

	}
	void replaceEdit()
	{

	}

	string getUndoPresentationName()
	{

	}
	string getRedoPresentationName()
	{

	}
private:
	bool isAlive;
	bool hasBeenDone;
	vector<UndoableEdit*> vector;
};

