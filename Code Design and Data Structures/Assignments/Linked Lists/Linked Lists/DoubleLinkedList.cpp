#include <iostream>
#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{

}
DoubleLinkedList::~DoubleLinkedList()
{

}

void DoubleLinkedList::pushFront(int value)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = head;
	if (head != NULL)
		head->prev = newNode;
	head = newNode;
}
void DoubleLinkedList::pushBack(int value)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = head;

	newNode->data = value;
	newNode->next = NULL;
	if (head == NULL)
	{
		newNode->prev = NULL;
		head = newNode;
		return;
	}

	while (last->next != NULL)
		last = last->next;
	
	last->next = newNode;
	newNode->prev = last;
	return;
}
void DoubleLinkedList::insert(struct Node* prevNode, int value)
{
	if (prevNode == NULL)
	{
		return;
	}

	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = prevNode->next;
	newNode->prev = prevNode;
	newNode->next = newNode;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}
void DoubleLinkedList::display()
{
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {
		std::cout << ptr->data << " " << std::endl;
		ptr = ptr->next;
	}
}

//int DoubleLinkedList::begin()
//{
//
//}
//int DoubleLinkedList::end()
//{
//
//}
//int DoubleLinkedList::first()
//{
//
//}
//int DoubleLinkedList::last()
//{
//
//}
int DoubleLinkedList::count()
{
	return sizeof(struct Node);
}

void DoubleLinkedList::deleteNode(struct Node* del)
{
	if (head == NULL || del == NULL)
		return;
	
	if (head == del)
		head = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);
}
void DoubleLinkedList::erase(int iterator)
{
	if (head == NULL || iterator <= 0)
		return;
	struct Node* current = head;

	for (int i = 1; current != NULL && i < iterator; i++)
		current = current->next;

	if (current == NULL)
		return;

	deleteNode(current);
}
void DoubleLinkedList::remove(int value)
{

}
void DoubleLinkedList::popBack()
{
	struct Node* last = head;

	if (head == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	if (head == last) {
		deleteNode(head);
		head = NULL;
		last = NULL;
	}

	struct Node* current = head;
	while (current->next != last)
		current = current->next;

	deleteNode(last);
	last = current;
	last->next = NULL;

}
void DoubleLinkedList::popFront()
{
	struct Node* last = head;

	if (head == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	if (head == last) {
		deleteNode(head);
		head = NULL;
		last = NULL;
	}

	struct Node* temp = head->next;

	deleteNode(head);
	head = temp;

}

bool DoubleLinkedList::empty()
{
	if (sizeof(struct Node) == 0)
		return true;
	else
		return false;
}

void DoubleLinkedList::clear()
{

	struct Node* current = head;

	while (head) {
		current = head;
		head = head->next;
		deleteNode(current);
	}

	head = NULL;
}