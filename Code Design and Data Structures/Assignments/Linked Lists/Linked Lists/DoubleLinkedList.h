#pragma once
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	struct Node
	{
		int data;
		struct Node *prev;
		struct Node *next;
	};

	struct Node* head = NULL;

	struct Node* tail = NULL;

	void pushFront(int value); // add a new value to the front of the list
	void pushBack(int value); // add a new value to the end of the list
	void insert(struct Node* prevNode, int value); // add a new value one-past the specified iterator location
	void display(); // displays the list
	int begin(); // return an iterator to the first element
	int end(); // return an iterator to a null element
	int first(); // return the first element by value, assert if no elements
	int last(); // return the last element by value, assert if no elements
	int count(); // return how many elements exist in the list
	void deleteNode(struct Node* del); // base delete function
	void erase(int iterator); // remove an element by its iterator
	void remove(int value); // remove all elements with matching value
	void popBack(); // remove the last element
	void popFront(); // remove the first element
	bool empty(); // return a Boolean, true if the list is empty, false otherwise
	void clear(); // remove all elements from the list

private:


};