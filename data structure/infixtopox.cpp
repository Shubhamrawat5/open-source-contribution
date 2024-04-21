#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
struct stack
{

    int data;
    struct stack *next;
};

struct stack *top = NULL;

int stck_top()
{
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        return top->data;
    }
}
void push(char m)
{

    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    p->data = m;
    p->next = top;
    top = p;
}

char pop()
{

    struct stack *q;
    char dat;
    q = top;
    dat = q->data;
    top = top->next;
    free(q);
    return dat;
}

int prec(char a)
{

    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
        return 2;

    else if (a == '+' || a == '-')
        return 1;

    else
        return 0;
}

int isopt(char ch)
{

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='^')
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

string posfix(string str)
{

    string pos;
    int i = 0;
    while (str[i] != '\0')
    {
        if (isopt(str[i]))
        {
             if (prec(str[i]) > prec(stck_top()))
            {

                push(str[i]);
                i++;
            }
            else
            {
                pos += pop();
            }
           
        }
        else
        {
            pos += str[i];
            i++;
        }
    }
    while (top != NULL)
    {
        pos += top->data;
        pop();
    }

    return pos;
}

int main()
{
    string s;
    cin >> s;
    cout << posfix(s);

    return 0;
}
