#include<iostream>

using namespace std;
void add(int a[], int x[]);
void complement(int a[])// function to take 2s complement of a binary number
{
    int i;
    int x[5] = {0};
    x[4] = 1;
    for (i = 0; i <5; i++)
    {
        a[i] = (a[i] + 1) % 2;
    }
    add(a, x);
}
void add(int ac[], int x[])// function to add two binary numbers
{
    int i, carry = 0;
    for (i = 4; i>=0; --i)
    {
        ac[i] = ac[i] + x[i] + carry;
        if (ac[i] > 1)
        {
            ac[i] = ac[i] % 2;
            carry = 1;
        }
        else
            carry = 0;
    }

}

void ashr(int ac[], int Q[])// function to left shift A and Q
{
    // int temp, i;

    // temp = ac[0];
    // qn = Q[0];
    int t=Q[0];
    for (int i =0; i<3;i++)
    {
        Q[i] =Q[i+1];
    }
    for (int i =0; i<4;i++)
    {
        ac[i]=ac[i+1];
    }
    ac[4]=t;

}

void display(int ac[], int Q[])// Function to display the quotient and remainder
{
    int i;
     cout <<"Remainder: ";
    for (i = 0; i<5;i++){
        cout <<ac[i];
    }
    cout<<"\n";
    cout << "Quotient: ";
     for (i = 0; i<4;i++){
        cout <<Q[i];
    }

}

int main()// main program 
{
    int mt[5], M[5], Q[4], c, ac[5] = { 0 };
    int i, temp,m,q;
    int qn=0;
    cout<<"Enter Dividend"<<endl;
    cin>>q;
    cout<<"Enter Divisor"<<endl;
    cin>>m;
    int k = 4; 
    while(k>=0){ 
        M[k]=m%2; 
          m= m/2; 
        k--; 
    }
    int j=3; 
    while(j>=0){ 
        Q[j]=q%2; 
          q= q/2; 
        j--; 
    }

    for (i =4;i>=0;i--){
        mt[i] = M[i]; 
    }
    complement(mt);
    c = 4;

    while (c != 0)
    {
        ashr(ac,Q);
        add(ac,mt);
        if(ac[0]==1){
            Q[3]=0;
            add(ac,M);
        }
        else{ 
            Q[3]=1;
        }
        c--;
    }
    display(ac,Q);
}
