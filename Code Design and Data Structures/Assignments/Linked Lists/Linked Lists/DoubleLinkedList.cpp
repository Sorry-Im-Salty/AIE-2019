#include <iostream>
#include "DoubleLinkedList.h"

template<class T>
DoubleLinkedList<T>::DoubleLinkedList()
{

}
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{

}

template<class T>
void DoubleLinkedList<T>::pushFront(int value)
{
	T* newNode = (T*) malloc(sizeof(T));
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
template<class T>
void DoubleLinkedList<T>::pushBack(int value)
{
	T* newNode = (T*) malloc(sizeof(T));
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
template<class T>
void DoubleLinkedList<T>::insert(T* Node, int value)
{
	T* n = (T*) malloc(sizeof(T));
	n->data = value;
	n->next = Node;

	if (Node != NULL) {
		n->prev = Node->prev;

		if (Node->prev != NULL)
			Node->prev->next = n;
		Node->prev = n;
	}

	if (head = Node)
		head = n;
	if (tail == NULL)
		tail = n;

}
template<class T>
void DoubleLinkedList<T>::display()
{
	T* ptr;
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
template<class T>
int DoubleLinkedList<T>::count()
{
	return sizeof(T);
}

template<class T>
void DoubleLinkedList<T>::deleteNode(T* del)
{
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
template<class T>
void DoubleLinkedList<T>::erase(int iterator)
{
	if (head == NULL || iterator <= 0)
		return;
	T* current = head;

	for (int i = 1; current != NULL && i < iterator; i++)
		current = current->next;

	if (current == NULL)
		return;

	deleteNode(current);
}
template<class T>
void DoubleLinkedList<T>::remove(int value)
{

}
template<class T>
void DoubleLinkedList<T>::popBack()
{
	tail = head;

	if (head == NULL)
		return;

	while (tail->next != NULL)
		tail = tail->next;

	if (head == tail) {
		deleteNode(head);
		head = NULL;
		tail = NULL;
	}

	T* current = tail;
		current = current->prev;

	deleteNode(tail);
	tail = current;
	tail->next = NULL;

}
template<class T>
void DoubleLinkedList<T>::popFront()
{
	tail = head;

	if (head == NULL)
		return;

	while (tail->next != NULL)
		tail = tail->next;

	if (head == tail) {
		deleteNode(head);
		head = NULL;
		tail = NULL;
	}

	T* temp = head->next;

	deleteNode(head);
	head = temp;

}

template<class T>
bool DoubleLinkedList<T>::empty()
{
	if (sizeof(struct Node) == 0)
		return true;
	else
		return false;
}

template<class T>
void DoubleLinkedList<T>::clear()
{

	T* current = head;

	while (head) {
		current = head;
		head = head->next;
		deleteNode(current);
	}

	head = NULL;
	tail = NULL;
}