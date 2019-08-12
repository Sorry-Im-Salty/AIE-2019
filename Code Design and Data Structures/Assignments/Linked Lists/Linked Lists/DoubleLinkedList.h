#pragma once
template <class T>
class DoubleLinkedList
{
public:
	DoubleLinkedList() {
		head = NULL;
		tail = NULL;
	}
	~DoubleLinkedList() {

	}

	struct Node {
		T data;
		Node *prev;
		Node *next;
	};

	Node* head;
	Node* tail;

	// add a new value to the front of the list
	void pushFront(T value) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = value;
		newNode->prev = NULL;
		newNode->next = head;
		if (head != NULL)
			head->prev = newNode;
		head = newNode;
		if (tail == NULL)
			tail = head;
		while (tail->next != NULL)
			tail = tail->next;
	}
	
	// add a new value to the end of the list
	void pushBack(T value) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		tail = head;

		newNode->data = value;
		newNode->next = NULL;
		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
			return;
		}

		while (tail->next != NULL)
			tail = tail->next;

		tail->next = newNode;
		newNode->prev = tail;
		return;
	}
	void insert(Node* prevNode, T value); // add a new value one-past the specified iterator location
	
	// displays the list
	void display() {
		Node* ptr;
		ptr = head;
		while (ptr != NULL) {
			std::cout << ptr->data << " " << std::endl;
			ptr = ptr->next;
		}
	}
	int begin(); // return an iterator to the first element
	int end(); // return an iterator to a null element
	int first(); // return the first element by value, assert if no elements
	int last(); // return the last element by value, assert if no elements
	int count(); // return how many elements exist in the list
	
	// base delete function
	void deleteNode(Node* del) {
		if (head == NULL || del == NULL)
			return;

		if (head == del)
			head = del->next;

		if (tail == del)
			tail = del->prev;

		if (del->next != NULL)
			del->next->prev = del->prev;

		if (del->prev != NULL)
			del->prev->next = del->next;

		free(del);
	}
	
	// remove an element by its iterator
	void erase(T iterator) {
		if (head == NULL || iterator <= 0)
			return;
		Node* current = head;

		for (int i = 1; current != NULL && i < iterator; i++)
			current = current->next;

		if (current == NULL)
			return;

		deleteNode(current);
	}
	void remove(T value); // remove all elements with matching value
	void popBack(); // remove the last element
	void popFront(); // remove the first element
	bool empty(); // return a Boolean, true if the list is empty, false otherwise
	void clear(); // remove all elements from the list

private:

};