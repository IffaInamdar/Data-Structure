#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int val) : data(val), next(nullptr){}
};

int main()
{
	node *n1, *n2, *n3, *n4, *n5, *head, *p1, *p2;

	
	n1 = new node(1);
    n2 = new node(2);
    n3 = new node(3);
    n4 = new node(4);
    n5 = new node(5);

	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n2;

	p1 = head;
	p2 = head;

	do
	{
		p1 = p1->next;
		p2 = p2->next->next;

	} while (p1 != p2);

	p1 = head;

	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	} ;
	cout << "misplaced linked : " << p1->data << endl;

	

	while (p1->next != p2)
	{

		p1 = p1->next;
	}

	cout << "tail node : " << p1->data << endl;

	p1->next = head;

	p1 = head;

	cout << "corrected link :" << endl;

	while (p1->next != head)
	{
		cout << p1->data << endl;
		p1 = p1->next;
	}

	cout << p1->data << endl;

	return 0;
}
