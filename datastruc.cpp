//Implement the operations of a dynamically allocated Stack data structure using a self-referential structure and single Linked List.
#include<iostream>
#include<cstdlib>
#include<cstdio> 
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
void push(Node *q)
{
	if(top==NULL)
		top=q;
	else
	{
		q->next=top;
		top=q;
	}
}
 
void pop(){
	if(top==NULL){
		cout<<"Stack is empty!!";
	}
	else{
		cout<<"Deleted element is "<<top->data;
		p=top;
		top=top->next;
		delete(p);
	}
}
 
void showstack()
{
	Node *q;
	q=top;
 
	if(top==NULL){
		cout<<"Stack is empty!!";
	}
	else{
		while(q!=NULL)
		{
			cout<<q->data<<" ";
			q=q->next;
		}		
	}
}

/*
 * Node Declaration
 */

struct dnode
{
    int info;
    struct dnode *next;
    struct dnode *prev;
}*start;
 
/*
 Class Declaration 
 */
class double_llist
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        double_llist()
        {
            start = NULL;  
        }
};

/*
 * Create Double Link List
 */
void double_llist::create_list(int value)
{
    struct dnode *s, *temp;
    temp = new(struct dnode);
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

/*
 * Insertion at the beginning
 */
void double_llist::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct dnode *temp;
    temp = new(struct dnode);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}



int main()
{
	int ch,x;
	Node *nptr;
	
	while(1)
	{
		cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Exit";
		cout<<"\nEnter your choice(1-4):";
		cin>>ch;
		
		switch(ch){
			case 1: cout<<"\nEnter data:";
					cin>>x;
					nptr=newnode(x);
					push(nptr);
					break;
			
			case 2: pop();
					break;
					
			case 3: showstack();
					break;
			
		        case 4: exit(0);
			
			default: cout<<"\nWrong choice!!";
		}
	}
	
	return 0;
}
 
