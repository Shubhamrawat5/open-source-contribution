/*Write a program to implement doubly linked list which supports the following operations:
(i) Insert an element x at the beginning of the doubly linked list
(ii) Insert an element x at position in the doubly linked list
(iii)Insert an element x at the end of the doubly linked list
(iv) Remove an element from the beginning of the doubly linked list
(v) Remove an element from position in the doubly linked list.
(vi) Remove an element from the end of the doubly linked list
(vii) Search for an element x in the doubly linked list and return its pointer
(viii) Concatenate two doubly linked lists*/

#include<iostream>
using namespace std;

template<class T>
class Dlink;
template<class T>
class node
{
private:
	T num;
	node* prev;
	node* next;
	friend class Dlink<T>;
};

template<class T>
class Dlink
{
public:
	Dlink();
	~Dlink();
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void addFront(const T&);
	void addBack(const T&);
	void removeFront();
	node<T>* getfront();
	node<T>* getback();
	void removeBack();
	void add_at_position(const T&,int i);
	void remove_from_position(int i);
	node<T>* search(const T& );
	void disp();
	void concatenate(node<T>*);
	int size();
private:
	node<T>* header;
	node<T>* trailer;
protected:
	void add(node<T>* ,const T&);
	void remove(node<T>*);
};

template<class T>
Dlink<T>::Dlink()
{
	header=new node<T>;
	trailer=new node<T>;
	header->next=trailer;
	trailer->prev=header;
}

template<class T>
Dlink<T>::~Dlink()
{
	while(!empty())
		removeFront();
	delete header;
	delete trailer;
}

template<class T>
bool Dlink<T>::empty() const
{
	return(header->next==trailer);
}

template<class T>
const T& Dlink<T>::front() const
{
	return header->next->num;
}

template<class T>
node<T>* Dlink<T>:: getfront()
{
	return header->next;
}

template<class T>
node<T>* Dlink<T>:: getback()
{
	return trailer->prev;
}

template<class T>
const T& Dlink<T>::back() const
{
	return trailer->prev->num;
}

template<class T>
void Dlink<T>::add(node<T>* v,const T& val)
{
	node<T>* u=new node<T>;
	u->num=val;
	u->next=v;
	u->prev=v->prev;
	v->prev->next=v->prev=u;
}

template<class T>
void Dlink<T>::addFront(const T& val)
{
	add(header->next,val);
}

template<class T>
void Dlink<T>::addBack(const T& val)
{
	add(trailer,val);
}

template<class T>
void Dlink<T>::remove(node<T>* v)
{
	node<T>* u =v->prev;
	node<T>* w =v->next;
	u->next=w;
	w->prev=u;
	delete v;
}

template<class T>
void Dlink<T>::removeFront()
{
	remove(header->next);
}

template<class T>
void Dlink<T>::removeBack()
{
	remove(trailer->prev);
}

template<class T>
void Dlink<T>::add_at_position(const T& val,int i)
{
	node<T>* h=header;
	int counter=1;
	if(i==0)
	{
		addFront(val);
		return;
	}
	while(counter<i-1)
	{
		h=h->next;
		counter++;
		if(i==1)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
	}
	add(h->next,val);
}

template<class T>
void Dlink<T>::remove_from_position(int i)
{
	node<T>* h=header;
	int counter=1;
	if(i==0)
	{
		removeFront();
		return;
	}
	while(counter<i-1)
	{
		h=h->next;
		counter++;
		if(i==1)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
	}
	remove(h->next);
}
template<class T>
int Dlink<T>::size()
{
	node<T>* h=header->next;
	int counter=1;
	while(h!=trailer)
	{
		counter++;
		h=h->next;
	}
	return counter;
}
template<class T>
node<T>* Dlink<T>::search(const T& val)
{
	node<T>* h=header;
	while(h!=trailer)
	{
		if(h->num==val)
		{
			cout<<"Value found "<<endl;
			return h->next;
		}
		h=h->next;
	}
	cout<<"Value not found!!"<<endl;
}

template<class T>
void Dlink<T>::disp()
{
	node<T>* h=header->next;
	while(h!=trailer)
	{
		cout<<h->num<<" ";
		h=h->next;
	}
	cout<<endl;
}

template <typename T>
void Dlink<T>::concatenate(node<T>* y) 
{
	node<T>* temp = header; 
	while (temp->next != trailer) {
		temp = temp->next;
	}
	temp->next = y;
	y->prev=trailer->prev;
	temp=header->next;
	while(temp->next->next!=trailer)
	{
		cout<<temp->num<<" ";
		temp=temp->next;
	}
}

int main()
{
	Dlink<int> d;
	Dlink<int> e;
	int ch;char repeat;
	int val,i;
	do
	{
	cout<<"Menu"<<endl;
	cout<<"1.Insert an element x at the beginning of the doubly linked list"<<endl;
	cout<<"2.Insert an element x at position ith in the doubly linked list"<<endl;
	cout<<"3.Insert an element x at the end of the doubly linked list"<<endl;
	cout<<"4.Remove an element from the beginning of the doubly linked list"<<endl;
	cout<<"5.Remove an element from position ith in the doubly linked list."<<endl;
	cout<<"6.Remove an element from the end of the doubly linked list"<<endl;
	cout<<"7.Search for an element x in the doubly linked list and return its pointer"<<endl;
	cout<<"8.Concatenate two doubly linked lists"<<endl;
	cout<<"9. Display "<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;

	switch(ch)
	{
		case 1:
		{
			cout<<"Enter the value "<<endl;
			cin>>val;
			d.addFront(val);
			break;
		}
		case 2:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			cout<<"Enter the position"<<endl;
			d.add_at_position(val,i);
			break;
		}
		case 3:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			d.addBack(val);
			break;
		}
		case 4:
		{
			d.removeFront();
			cout<<"Deleted"<<endl;
			break;
		}
		case 5:
		{
			cout<<"Enter the position"<<endl;
			cin>>i;
			d.remove_from_position(i);
			cout<<"Deleted"<<endl;
			break;
		}
		case 6:
		{
			d.removeBack();
			cout<<"Deleted"<<endl;
			break;
		}
		case 7:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			cout<<"Pointer : "<<d.search(val);
			break;
		}
		case 8:
		{
			cout<<"Enter values in second list "<<endl;
			repeat='y';
			while(repeat=='Y'||repeat=='y')
			{
				cout<<"Enter the value "<<endl;
				cin>>val;
				e.addBack(val);
				cout<<"Do you want to enter more(Y/N)?"<<endl;
				cin>>repeat;
			}
			d.concatenate(e.getfront());
			break;
		}
		case 9:
		{
			d.disp();
			e.disp();
			break;
		}
		default:
		{
			cout<<"Wrong choice "<<endl;
			break;
		}

	}
	cout<<"Do you want to continue(Y/N)?"<<endl;
	cin>>repeat;
	}
	while(repeat=='Y'||repeat=='y');
	return 0;
}

