#include "linked_list.h"
#include <iostream>
using namespace std;




List::List()
{
	Size = 0;
	head = nullptr;

}



List::~List()
{
	clear();
}



void List::pop_front()
{
	if (Size != 1) {
		Node* temp = head;

		head = head->pNext;
		head->pPrev = nullptr;

		delete temp;

		Size--;
	}
	else {
		Size--;
		delete head;
	}

}


void List::push_back(int data)
{
	if (head == nullptr)
	{

		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
		tail = current->pNext;

	}

	Size++;
}


void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}



List::Node& List::operator[](const int index)
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return *current;
		}
		current = current->pNext;
		counter++;
	}
}

void List::print()
{
	Node* current = head;
	int i = 0;
	cout << "head -> ";
	while (current) {
		cout << current->data<<" -> ";
		current = current->pNext;
	}
	cout << "tail" << endl;
}


void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}


void List::insert(int data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;
		newNode->pPrev = previous;
		newNode->pNext->pPrev = newNode;
		Size++;
	}





}


void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node* toDelete = previous->pNext;
		toDelete->pNext->pNext = previous;
		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}


void List::pop_back()
{
	removeAt(Size - 1);
}


