#include <iostream>			
#include <string>						//ALPER YILMAZ
#include <stdlib.h>						//150160702

using namespace std;

class Node{ // Node's items

public:

	int data;
	Node* next;
	Node* prev;

};

class ARTraverser{// traverser according to two type ARTF and ARTL

protected:

	Node* current;

public:
	virtual bool hasNode() = 0;
	virtual Node* next() = 0;

};
class AdderRemover{
	friend class ARTraverser;
protected:

	Node* head;
	Node* tail;
	string name;
	ARTraverser* traverser;
	int nodeCount;
public:
	virtual void add(int) = 0;
	virtual void remove() = 0;
	virtual void setTraverser() = 0;

	void display();
	void removeAll();
	void traverse();
	AdderRemover(){ 
		head = NULL;
		tail = NULL;
		traverser = NULL;
		nodeCount = 0;
	};
};

class ARTF : public ARTraverser{ //  traverse from the beginning element to the end element 

public:
	bool hasNode();
	Node* next();

	ARTF(Node* x){
		current = x;

	}
};

bool ARTF::hasNode()   // is there node?
{
	if (current != NULL)
		return true;
	else
		return false;

}
Node* ARTF::next()    // go next element and  return current element
{
	Node* temp = new Node;
	temp = current;
	current = current->next;
	return temp;
}

class ARTL : public ARTraverser{//  traverse from the end element to the beginning element 
public:

	bool hasNode();
	Node* next();
	ARTL(Node* x)
	{
		current = x;
	}
};
bool ARTL::hasNode()    // is there node?
{
	if (current != NULL)
		return true;
	else
		return false;
}
Node* ARTL::next() // go next element and  return current element
{
	Node* temp = new Node;
	temp = current;
	current = current->prev;
	return temp;
}

void AdderRemover::removeAll()  // remover all elements
{
	Node *temp;
	while (head){
		temp = head;
		head = head->next;
		delete temp;
	}
	nodeCount = 0;
}

void AdderRemover::display()    // display without traverser
{
	cout << name << "|" << "NodeCount:" << nodeCount << endl;
	if (nodeCount == 0)
	{
		cout << "There is no element to print" << endl;
	}
	while (head)
	{
		cout << head->data << endl;
		head = head->next;
	}

}
void AdderRemover::traverse()   // Traverse by using traverser
{ 
	cout << name << "|" << "NodeCount:" << nodeCount << endl;
		if (traverser->hasNode() == false)
			cout << "No Element";

	for (int i = 0; i < nodeCount; i++)
		cout<<traverser->next()->data<<endl;
}

class FAFR : public AdderRemover{
public:

	void add(int);
	void remove();
	void setTraverser();
	FAFR()
	{
		name = "FAFR";
	}
};
void FAFR::setTraverser()
{
	traverser=new ARTF(head);
	
}
void FAFR::add(int a)  // adding the first of the sequence
{
	Node* iter, *newNode;
	newNode = new Node;
	newNode->data = a;
	newNode->next = NULL;
	newNode->prev = NULL;
	iter = head;

	if (head == NULL)
	{
		head = newNode;
		tail = head;
		nodeCount++;
	}
	else
	{

		newNode->next = head;
		head = newNode;
		(newNode->next)->prev = newNode;
		nodeCount++;
		while (iter->next)
		{
			iter = iter->next;

		}
		tail = iter;
	}
}
void FAFR::remove() // removing first element of sequence
{
	Node* temp;
	temp = new Node;
	temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
	nodeCount--;

}


class FALR : public AdderRemover{

public:

	void add(int);
	void remove();
	void setTraverser();

	FALR()
	{
		name = "FALR";
	}
};
void FALR::setTraverser()
{
	traverser = new ARTF(head);

}
void FALR::add(int a)  // adding the last of the sequence
{
	Node* iter, *newNode;
	newNode = new Node;
	newNode->data = a;
	newNode->next = NULL;
	newNode->prev = NULL;
	iter = head;

	if (head == NULL)
	{
		head = newNode;
		tail = head;
		nodeCount++;
	}
	else
	{

		newNode->next = head;
		head = newNode;
		(newNode->next)->prev = newNode;
		nodeCount++;
		while (iter->next)
		{
			iter = iter->next;

		}
		tail = iter;
	}
}
void FALR::remove()    // removing last element of sequence
{
	tail = tail->prev;
	tail->next = NULL;
	nodeCount--;
}


class LAFR : public AdderRemover{
public:
	void add(int);
	void remove();
	void setTraverser();
	LAFR()
	{
		name = "LAFR";
	}
};
void LAFR::setTraverser()
{
	traverser = new ARTL(tail);

}
void LAFR::add(int a) // adding the last of the sequence
{
	Node* iter, *newNode;
	newNode = new Node;
	newNode->data = a;
	newNode->next = NULL;
	newNode->prev = NULL;
	iter = head;

	if (head == NULL)
	{
		head = newNode;
		tail = head;
		nodeCount++;
	}
	else
	{

		while (iter)
		{
			iter = iter->next;

		}
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;

		nodeCount++;


	}
}

void LAFR::remove()  // removing first element of sequence
{
	Node* temp;
	temp = new Node;
	temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
	nodeCount--;

}


class LALR : public AdderRemover{ 
public:
	void add(int);
	void remove();
	void setTraverser();
	LALR()
	{
		name = "LALR";
	}

};
void LALR::setTraverser()
{
	traverser = new ARTL(tail);

}
void LALR::add(int a)  // adding the last of the sequence
{
	Node* iter, *newNode;
	newNode = new Node;
	newNode->data = a;
	newNode->next = NULL;
	newNode->prev = NULL;
	iter = head;

	if (head == NULL)
	{
		head = newNode;
		tail = head;
		nodeCount++;
	}
	else
	{

		while (iter)
		{
			iter = iter->next;

		}
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;

		nodeCount++;


	}
}
void LALR::remove()  // removing last element of sequence
{
	tail = tail->prev;
	tail->next = NULL;
	nodeCount--;
}




int main()  // main codes
{
	AdderRemover *myList[4];

	myList[0] = new FAFR();
	myList[1] = new LALR();
	myList[2] = new FALR();
	myList[3] = new LAFR();

	for (int j = 0; j<4; j++) {
		for (int i = 0; i<5; i++)
			myList[j]->add(i);
	}

	for (int j = 0; j<4; j++){
		myList[j]->remove();
		myList[j]->display();
		myList[j]->removeAll();
		myList[j]->display();
	}


	cout << endl << "Test case for ARTraverser" << endl;
	for (int j = 0; j<4; j++) {
		for (int i = 0; i<5; i++)
			myList[j]->add(i);
		myList[j]->remove();
	}

	for (int j = 0; j<4; j++){
		myList[j]->setTraverser();
		myList[j]->traverse();
	}
	system("PAUSE");
}
