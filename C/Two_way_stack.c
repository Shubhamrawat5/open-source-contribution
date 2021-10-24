#include <stdio.h>
#include <stdlib.h>

struct two_stack
{
	int capacity;
	int top_left;
	int top_right;
	int *arr;
};

struct two_stack * create_stack(int cap)
{
	struct two_stack *s;
	s=(struct two_stack *)malloc(sizeof(struct two_stack));
	s->capacity=cap;
	s->top_left=-1;
	s->top_right=cap;
	s->arr=(int *)malloc(sizeof(int) * cap);
	return s;
}

void push_left(struct two_stack *s, int data)
{
	if(s->top_left==-1)
	{
		s->top_left=0;
		s->arr[s->top_left]=data;
	}
	else if(s->top_left== s->top_right-1)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top_left+=1;
		s->arr[s->top_left]=data;
	}
}

void push_right(struct two_stack *s, int data)
{
	if(s->top_right==s->capacity)
	{
		s->top_right=s->capacity-1;
		s->arr[s->top_right]=data;
	}
	else if(s->top_right== s->top_left+1)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top_right-=1;
		s->arr[s->top_right]=data;
	}
}

int pop_left(struct two_stack *s)
{
	int data;
	if(s->top_left==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		data=s->arr[s->top_left];
		s->top_left-=1;
	}
	return data;
}

int pop_right(struct two_stack *s)
{
	int data;
	if(s->top_right==s->capacity)
	{
		printf("Underflow\n");
	}
	else
	{
		data=s->arr[s->top_right];
		s->top_right+=1;
	}
	return data;
}

void peek_left(struct two_stack *s)
{
	if(s->top_left==-1)
	{
		printf("Stack 1 is empty\n");
	}
	else
	{
		printf("Top left element: %d\n",s->arr[s->top_left]);
	}
}

void peek_right(struct two_stack *s)
{
	if(s->top_right==s->capacity)
	{
		printf("Stack 2 is empty\n");
	}
	else
	{
		printf("Top right element: %d\n",s->arr[s->top_right]);
	}
}


int main()
{	
	int v1, v2;

	struct two_stack *s1;
	s1=create_stack(8);
	push_left(s1, 10);
	push_left(s1, 20);
	
	push_left(s1, 30);
	push_left(s1, 40);

	push_right(s1, 90);
	push_right(s1, 80);
	push_right(s1, 70);
	push_right(s1, 60);

	pop_right(s1);
	pop_left(s1);
	pop_left(s1);
	
	peek_left(s1);
	peek_right(s1);
	return 0;
}