#include<iostream>
#include<vector>
using namespace std;

class UndoableEdit
{
public: 
	UndoableEdit(string _actionName):presentationName(_actionName),isAlive(true),hasBeenDone(true)
	{

	}
	~UndoableEdit() 
	{
		//delete[] vector;
	}
	bool canUndo()
	{
		if (isAlive && hasBeenDone)
			return true;
		else
			return false;
	}
	void undo()
	{
		if (canUndo())
		{
			hasBeenDone = false;
			cout << getUndoPresentationName() << endl;
		}
		else
			cout << "Error";
	}
	bool canRedo()
	{
		if (isAlive && !hasBeenDone)
			return true;
		else
			return false;
	}
	void redo()
	{
		if (canRedo())
		{
			hasBeenDone = true;
			cout << getRedoPresentationName() << endl;
		}
	}
	virtual void addEdit(UndoableEdit* _edit)
	{

	}
	virtual void replaceEdit(UndoableEdit* _edit)
	{

	}
	string getPresentationName()
	{
		return presentationName;
	}
	string getUndoPresentationName()
	{
		return "Undo " + presentationName;
	}
	string getRedoPresentationName()
	{
		return "Redo " + presentationName;
	}
protected:
	bool isAlive;
	bool hasBeenDone;
	string presentationName;
};
//Implentatino of UndoableEidt


class MyUndoableEdit :public UndoableEdit
{
public:
	MyUndoableEdit(string _name);
	~MyUndoableEdit();
};
// Implentation of MyUndoableEdit
MyUndoableEdit::MyUndoableEdit(string _name) :UndoableEdit(_name) {}
MyUndoableEdit::~MyUndoableEdit() {}


class CompoundEdit :public UndoableEdit
{
public:
	CompoundEdit(string);
	~CompoundEdit();
	void addEdit(UndoableEdit* _edit);
	void replaceEdit(UndoableEdit* _edit);
private:
	vector<UndoableEdit*> vector;
};
// Implentation of CompoundEdit
CompoundEdit::CompoundEdit(string _name) : UndoableEdit(_name) {}
CompoundEdit::~CompoundEdit() {}
void CompoundEdit::addEdit(UndoableEdit* _edit)
{
	vector.push_back(_edit);
}
void CompoundEdit::replaceEdit(UndoableEdit* _edit) {

}


////////////////////////////////////////////////////////////////
// Class UndoManager
class UndoManager :public UndoableEdit {
public:
	UndoManager(string _name,int limit = 100);
	~UndoManager();
	int getLimit();
	void setLimit(int _limit);
	void discardAllEdits();
	void undoTo(UndoableEdit* _edit);
	void redoTo(UndoableEdit* _edit);
	void undoOrRedo();
	bool canUndoOrRedo();

	void addEdit(UndoableEdit* _edit);
	void replaceEdit(UndoableEdit* _edit);

	void printList();

	void undo();
	void redo();
	bool canUndo();
	bool canRedo();
	

private:
	int limit;
	int indexOfNextAdd;
	vector<UndoableEdit*> edits;
};
// Implement of UndoManager
UndoManager::UndoManager(string _name,int _limit):UndoableEdit(_name),limit(_limit){
	indexOfNextAdd = 0;
}
UndoManager::~UndoManager() {

}
int UndoManager::getLimit() {
	return limit;
}
void UndoManager::setLimit(int _limit) {
	limit = _limit;
}
void UndoManager::discardAllEdits() {
	indexOfNextAdd = 0;
}
void UndoManager::undoTo(UndoableEdit* _edit) {

}
void UndoManager::redoTo(UndoableEdit* _edit) {

}
void UndoManager::undoOrRedo() {

}
bool UndoManager::canUndoOrRedo() {
	if (canUndo() || canRedo())
		return true;
}
void UndoManager::addEdit(UndoableEdit* _edit)
{
	if (indexOfNextAdd < edits.size())
		edits[indexOfNextAdd] = _edit;
	else
		edits.push_back(_edit);
	indexOfNextAdd++;
}
void UndoManager::replaceEdit(UndoableEdit* _edit) {

}
void UndoManager::printList() {
	int i = 0;
	for (vector<UndoableEdit*>::iterator it = edits.begin();it < edits.end() && i < indexOfNextAdd;it++,i++) {
		cout << (*it)->getPresentationName() << endl;
	}
}

void UndoManager::undo(){
	int last = indexOfNextAdd - 1;
	if (last)
	{
		edits[last]->undo();
		indexOfNextAdd--;
	}
	
}
void UndoManager::redo() {
	edits[indexOfNextAdd]->redo();
	indexOfNextAdd++;
}
bool UndoManager::canUndo() {
	return edits[indexOfNextAdd-1]->canUndo();
}
bool UndoManager::canRedo() {
	return edits[indexOfNextAdd]->canRedo();
}