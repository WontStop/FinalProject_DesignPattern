#include<iostream>
#include<vector>

#define UndoableEdit_MyUndoableEdit 1;
#define UndoableEdit_CompundEdit 2
using namespace std;

class UndoableEdit
{
public:
	UndoableEdit(string _actionName) :presentationName(_actionName), isAlive(true), hasBeenDone(true)
	{
		type = UndoableEdit_MyUndoableEdit;
	}
	~UndoableEdit()
	{

	}
	virtual bool canUndo()
	{
		if (isAlive && hasBeenDone)
			return true;
		else
			return false;
	}
	virtual void undo()
	{
		if (canUndo())
		{
			hasBeenDone = false;
			cout << getUndoPresentationName() << endl;
		}
		else
			cout << getUndoPresentationName() << " error!!!" << endl;
	}
	virtual bool canRedo()
	{
		if (isAlive && !hasBeenDone)
			return true;
		else
			return false;
	}
	virtual void redo()
	{
		if (canRedo())
		{
			hasBeenDone = true;
			cout << getRedoPresentationName() << endl;
		}
		else
			cout << getRedoPresentationName() << " error!!!" << endl;
	}
	virtual void die() {
		isAlive = false;
	}
	virtual void addEdit(UndoableEdit* _edit) {
		// to be implemented by its subclass
	}
	virtual void replaceEdit(UndoableEdit* _edit) {
		// to be implemented by its subclass
	}
	virtual string getPresentationName()
	{
		return presentationName;
	}
	virtual string getUndoPresentationName()
	{
		return "Undo " + presentationName;
	}
	virtual string getRedoPresentationName()
	{
		return "Redo " + presentationName;
	}
	virtual int getType() {
		return type;
	}
protected:
	bool isAlive;
	bool hasBeenDone;
	string presentationName;
	int type;
};
//Implentatino of UndoableEidt


class MyUndoableEdit :public UndoableEdit
{
public:
	MyUndoableEdit(string _name);
	~MyUndoableEdit();
};
// Implentation of MyUndoableEdit
MyUndoableEdit::MyUndoableEdit(string _name) :UndoableEdit(_name) {
	type = UndoableEdit_MyUndoableEdit;
}
MyUndoableEdit::~MyUndoableEdit() {}


class CompoundEdit :public UndoableEdit
{
public:
	CompoundEdit(string);
	~CompoundEdit();
	bool canUndo();
	void undo();
	bool canRedo();
	void redo();
	string getPresentationName();
	string getUndoPresentationName();
	string getRedoPresentationName();

	void addEdit(UndoableEdit* _edit);

private:
	vector<UndoableEdit*> edits;
};
// Implentation of CompoundEdit
CompoundEdit::CompoundEdit(string _name) : UndoableEdit(_name) {
	type = UndoableEdit_CompundEdit;
}
CompoundEdit::~CompoundEdit() {}
bool CompoundEdit::canUndo() {
	bool canUndoFlag = true;
	for (int current = 0;current < edits.size();current++) {
		if (!edits[current]->canUndo())
			canUndoFlag = false;
	}
	return canUndoFlag;
}
void CompoundEdit::undo() {
	if (canUndo()) {
		hasBeenDone = false;
		cout << getUndoPresentationName() << endl;

		for (int i = 0;i < edits.size();i++) {
			edits[i]->undo();
		}
	}
	else
		cout << getUndoPresentationName() << " error!!!" << endl;
}
bool CompoundEdit::canRedo() {
	bool canRedoFlag = true;
	for (int current = 0;current < edits.size();current++) {
		if (!edits[current]->canRedo())
			canRedoFlag = false;
	}
	return canRedoFlag;
}
void CompoundEdit::redo() {
	if (canRedo()) {
		hasBeenDone = true;
		cout << getRedoPresentationName() << endl;

		for (int i = 0;i < edits.size();i++) {
			edits[i]->redo();
		}
	}
	else
		cout << getRedoPresentationName() << " error!!!" << endl;
	
}
void CompoundEdit::addEdit(UndoableEdit* _edit)
{
	edits.push_back(_edit);
}
string CompoundEdit::getPresentationName() {
	return presentationName;
}
string CompoundEdit::getUndoPresentationName() {
	return "Undo " + presentationName;
}
string CompoundEdit::getRedoPresentationName() {
	return "Redo " + presentationName;
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

	if (indexOfNextAdd > 0)
	{
		//Same
		if (edits[indexOfNextAdd - 1]->getPresentationName() == _edit->getPresentationName())
		{
			//Compound
			if (edits[indexOfNextAdd - 1]->getType() == UndoableEdit_CompundEdit) {			
				edits[indexOfNextAdd - 1]->addEdit(_edit);
			}
			//Edit
			else {																			
				CompoundEdit* compound = new CompoundEdit(_edit->getPresentationName());
				compound->addEdit(edits[indexOfNextAdd - 1]);
				compound->addEdit(_edit);
				replaceEdit(compound);
			}
		}
		//Different
		else
		{
			if (indexOfNextAdd < edits.size())
			{
				edits[indexOfNextAdd] = _edit;
				indexOfNextAdd++;
			}
			else
			{
				edits.push_back(_edit);
				indexOfNextAdd++;
			}
		}
	}
	else 
	{
		if (indexOfNextAdd < edits.size())
		{
			edits[indexOfNextAdd] = _edit;
			indexOfNextAdd++;
		}
		else
		{
			edits.push_back(_edit);
			indexOfNextAdd++;
		}
	}


	//make all the action after this action die
	if (indexOfNextAdd < edits.size()){
		for (int current = indexOfNextAdd;current < edits.size();current++){
			edits[current]->die();
		}
	}
	if (indexOfNextAdd >= 100)
		cout << "Warning...Out of Limit...";
}
void UndoManager::replaceEdit(UndoableEdit* _edit) {
	/* no replace functions...
	for (vector<UndoableEdit*>::iterator it = edits.begin();it < edits.end();it++) {
		if (*it == _edit) {
			(*it) = _edit;
			
			break;
		}
	}
	*/

	//OK I know how to write it......
	if (indexOfNextAdd - 1 >= 0) {
		edits[indexOfNextAdd - 1] = _edit;
	}
}
void UndoManager::printList() {
	cout << "*************Action List(start)*************" << endl;
	int i = 0;
	for (vector<UndoableEdit*>::iterator it = edits.begin();it < edits.end() && i < indexOfNextAdd;it++,i++) {
		cout << (*it)->getPresentationName() << endl;
	}
	cout << "*************Action List(over)**************" << endl;

}
void UndoManager::undo(){
	int last = indexOfNextAdd - 1;
	if (last>=0)
	{
		edits[last]->undo();
		indexOfNextAdd--;
	}
}
void UndoManager::redo() {
	if (indexOfNextAdd < edits.size())
	{
		if (edits[indexOfNextAdd]->canRedo())
			indexOfNextAdd++;
		edits[indexOfNextAdd - 1]->redo();
	}
	else
		cout << "Our of Range" << endl;
	
}
bool UndoManager::canUndo() {
	return edits[indexOfNextAdd-1]->canUndo();
}
bool UndoManager::canRedo() {
	return edits[indexOfNextAdd]->canRedo();
}