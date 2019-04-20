//Implement the operations of a dynamically allocated Stack data structure using a self-referential structure and single Linked List.
#include<iostream>
#include<cstdlib>
 
using namespace std;
 
struct Node
{
	int data;
	Node *next;
}*top=NULL,*p;
 
Node* newnode(int x)
{
	p=new Node;
	p->data=x;
	p->next=NULL;
	return(p);
}

