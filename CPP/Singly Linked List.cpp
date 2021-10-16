/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at position in the singly linked list
(iii)Remove an element from the beginning of the singly linked list
(iv) Remove an element from position in the singly linked list.
(v) Search for an element x in the singly linked list and return its pointer
(vi) Concatenate two singly linked lists*/

#include<iostream>
using namespace std;
template<class T>
class list;
template<class T>
class node
{
	T num;
	node<T> *next;
	friend class list<T>;
	node(const T& val)
	{
		num=val;
	}
};

template<class T>
class list
{
private:
	node<T>* head;

public:
	list();
	~list();
	bool empty() const;
	void addFront(const T&);
	void removeFront();
	void disp();
	node<T>* front();
	void add_at_position(const T&,int i);
	void remove_from_position(int i);
	node<T>* search(const T&);
	void concatenate(node<T> *);
};

template<class T> 
list<T>::list()
{
	head=NULL;
}
template<class T>
list<T>::~list()
{
	while(!empty())
		removeFront();
}

template<class T>
void list<T>::disp()
{
	node<T> *h=head;
	if(h==NULL)
		cout<<"list is empty!"<<endl;
	while(h!=0)
	{
		cout<<h->num<<" ";
		h=h->next;
	}
	cout<<endl;
}

template<class T>
void list<T>::addFront(const T& val)
{
	node<T> *n=new node<T>(val);
	n->num=val;
	n->next=head;
	head=n;
}

template<typename T>
node<T>* list<T>	::front()
{
	return head;
}

template<class T>
void list<T>::removeFront()
{
	node<T>*temp=head;
	head=temp->next;
	delete temp;
}

template<class T>
bool list<T>::empty() const
{
	return head==NULL;
}

template<class T>
void list<T>::add_at_position(const T& val, int i)
{
	if(i==1)
	{
		addFront(val);
		return;
	}
	node<T> *n=head;
	int counter=1;
	while(counter<i-1)
	{
		n=n->next;
		if(n==0)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		counter++;
	}
	node <T>* m=n->next;
	n->next=new node<T>(val);
	n->next->next=m;
}

template<class T>
void list<T>::remove_from_position(int i)
{
	if(i==1)
	{
		removeFront();
		return;
	}
	node<T> *n=head;
	int counter=1;
	while(counter<i-1)
	{
		n=n->next;
		if(n==0)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		counter++;
	}
	node <T>*m=n->next->next;
	delete n->next;
	n->next=m;
}

template<class T>
node<T>* list<T>::search(const T& x)
{
	node<T> *n=head;
	while(n!=0)
	{
		if(n->num==x)
		{
			cout<<"Value "<<n->num<<" found !!"<<endl;
			return n->next;
		}
		n=n->next;
	}
	cout<<"Value not found"<<endl;
}
template <typename O>
void list<O>::concatenate(node<O>* y) {
	node<O>* temp = head; //creates Node pointer
	while (temp->next != NULL) {
		temp = temp->next; //traverse untill end of the list
	}
	temp->next = y; //set last's link to first of second list
}
int main()
{
	list<int> n;
	list<int> m;
	int val,i;
	int ch;
	char repeat;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"1.Add in the beginning"<<endl;
		cout<<"2.Add at a position"<<endl;
		cout<<"3.Delete from the beginning"<<endl;
		cout<<"4.Delete from a position"<<endl;
		cout<<"5.Search for an element"<<endl;
		cout<<"6.Concatenating two strings"<<endl;
		cout<<"7.Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				n.addFront(val);
				break;
			}
			case 2:
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				cout<<"Enter the position "<<endl;
				cin>>i;
				n.add_at_position(val,i);
				break;
			}
			case 3:
			{
				n.removeFront();
				cout<<"Deleted from the beginning"<<endl;
				break;
			}
			case 4:
			{
				cout<<"Enter the position"<<endl;
				cin>>i;
				n.remove_from_position(i);
				cout<<"Deleted from "<<i<<endl;
				break;
			}
			case 5:
			{
				cout<<"Enter the value to be searched"<<endl;
				cin>>val;
				cout<<"Address : "<<n.search(val)<<endl;
				break;
			}
			case 6:
			{
				cout<<"Enter another list "<<endl;
				cout<<"Enter the size of the list"<<endl;
				cin>>i;
				for(int j=1;j<=i;j++)
				{
					cout<<"Enter values "<<endl;
					cin>>val;
					m.add_at_position(val,j);
				}
				n.concatenate(m.front());
				cout<<"After Concatenating "<<endl;	
			}
			case 7:
			{
				cout<<"Displaying the first list "<<endl;
				n.disp();
				cout<<"Displaying the second list "<<endl;
				m.disp();
				break;
			}
			default:
			{
				cout<<"Wrong choice"<<endl;
				break;
			}
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>repeat;
	}
	while(repeat=='y'||repeat=='Y');
	return 0;
}