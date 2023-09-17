#include <iostream>
#include"linked_list.h"
using namespace std;

int main()
{


	List lst;

	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(101);
	
	cout << lst[2].data<<endl;

	lst.print();
	cout << endl << "pop_back " << endl << endl;

	lst.pop_back();


	lst.print();
	return 0;
}

