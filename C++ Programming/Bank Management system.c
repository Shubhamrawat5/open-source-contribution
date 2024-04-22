#include<stdio.h>
typedef struct management {
    int acc;
    char user[50] ;
    char doj[30] ;
    float amt = 0;
    float bal = 0;



}mng;


void menu()
{
    printf("-------------------------------------------\n");
    printf("1.Create account\n");
    printf("2.Show details\n");
    printf("3.Withdrawl\n");
    printf("4.Deposit\n");
    printf("\n-------------------------------------------\n");

}

void create(mng *m1)
{
    printf("Enter Account Number:");
    scanf(" %d", &(*m1).acc);
    printf("Enter Account Holder Name:");
    scanf(" %s", (*m1).user);
    printf("Enter date[dd-mm-yy]:");
    scanf(" %s", (*m1).doj);
    printf("Enter amount to be deposit:");
    scanf("%f", &(*m1).amt);
    (*m1).bal+=(*m1).amt;

}


void details(mng m1)
{
    printf("Account Number:%d\n",m1.acc);
    printf("Account Holder Name:%s\n",m1.user);
    printf("Date of Joined[dd-mm-yy]:%s\n",m1.doj);
    printf("Balance:%0.2f\n",m1.amt);
}


void deposit(mng *m1)
{
    printf("Your current balance is:%0.2f\n",(*m1).bal);
    printf("Enter amount to be deposit:");
    scanf("%f",&(*m1).amt);
    (*m1).bal+=(*m1).amt;
    printf("Updated balance:%0.2f\n",(*m1).bal);
}

void withdrawal(mng *m1)
{
    printf("Your current balance is:%0.2f\n",(*m1).bal);
    printf("Enter amount to be withdrawl:");
    scanf("%f",&(*m1).amt);
    (*m1).bal-=(*m1).amt;
    printf("Updated balance:%0.2f\n",(*m1).bal);
}


int main()
{
    char ch , cn='y';
    int i=0;

     mng usr[50];
     mng *ptr=usr;





    do {
        printf("\n-------------------------------------------\n");
        printf("\tBank Management System \t\n");
        menu();
        printf("Enter your choice:");
        scanf(" %c",&ch);
        if (ch=='1')
        {
          printf("\n__________________________________________\n");
          printf("Record of id:-%d\n",i);
          create( ptr);
          printf("Record updated successfully.....\n");
          i++;
          ptr++;

        }
        else if (ch=='2')
        {
         int a;
        printf("\n__________________________________________\n");

         printf("Enter id of user[0-50]");
         scanf("%d",&a);
         printf("Please wait while we reteriving data......\n");
         details(usr[a]);
        }
        else if (ch=='3')
        {
            int b;
            printf("\n__________________________________________\n");
            printf("Enter id of your account:");
            scanf("%d", &b);
            withdrawal(&usr[b]);
        }
        else if (ch=='4')
        {
            int c;
            printf("\n__________________________________________\n");
            printf("Enter id of your account:");
            scanf("%d", &c);
            deposit(&usr[c]);
        }
        printf("Do you want to continue (y/n):");
        scanf(" %c", &cn);






    }while (cn =='y');


    return 0;
}
