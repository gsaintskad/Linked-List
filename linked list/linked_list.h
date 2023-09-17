#pragma once
#include <iostream>
using namespace std;






class List
{

private:


	
	class Node{
	public:
		Node* pNext;
		Node* pPrev;
		int data;
		Node(int data=0, Node* pNext = nullptr , Node* pPrev = nullptr)
		{

			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;
	Node* head;
	Node* tail;
public:
	List();
	~List();


	void pop_front();


	void push_back(int data);


	void clear();


	int size() { return Size; }


	Node& operator[](const int index);

	void print();

	void push_front(int data);


	void insert(int data, int index);


	void removeAt(int index);


	void pop_back();

};

