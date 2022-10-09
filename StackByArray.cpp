#include<iostream>
#define MAX 100
using namespace std;

//array implementation of stack!
class Stack
{
	int top;
	public:
	int a[MAX];
	Stack()
	{
		top=0;
	}
	bool push(int x);
	int pop();
	bool isEmpty();	
	int peek();
	void display();
};

bool Stack::push(int x)
{
	if(top>=MAX)
	{
		cout<<"\nSTACK OVERFLOW!";
		return 0;
	}
	else
	{
		a[top++]=x;
		cout<<"\nSuccessfully Pushed : "<<x;
		return 1;
	}
}

int Stack::pop()
{
	if(top<=0)
	{
		cout<<"\nSTACK UNDERFLOW!";
		return 0;
	}
	else
	{
		//cout<<"\nSuccessfully Pop : "<<a[top-1];
		int x=a[top-1];
		--top;
		return x;
	}
}

bool Stack::isEmpty()
{
	return(!top);
}

int Stack::peek()
{
	if(top==0)
	{
		cout<<"\nSTACK IS EMPTY! ";
		return -1;
	}
	else
	{
		return(a[top-1]);
	}
}

void Stack::display()
{
	if(top<=0)
	{
		cout<<"\nSTACK IS EMPTY! ";
	}
	else
	{
		cout<<"\nCurrent Stack : ";
		for(int i=0;i<top;++i)
		cout<<a[i]<<" ";
	}
	
}

int main()
{
	Stack s;
	int choice=1;
	cout<<"1 to push\n2 to pop\n3 to display\n4 to get top element\n5 to check if stack empty\n";
	while(choice)
	{
		cout<<"\nEnter choice: ";
		cin>>choice;
	if(choice==1)
	{
		int ele;
		cout<<"\nEnter element to push: ";
		cin>>ele;
		s.push(ele);
	}
	else if(choice==2)
	{
		cout<<"\n";
		cout<<s.pop()<<" is popped from stack";
	}
	else if(choice==3)
	{
		s.display();
	}
	else if(choice==4)
	{
		cout<<"\n";
		if(s.peek()!=-1)
		cout<<s.peek()<<" is on top";
	}
	else if(choice==5)
	{
		s.isEmpty()?cout<<"\nStack is empty!":cout<<"\nStack is not empty!";
	}
}
}
