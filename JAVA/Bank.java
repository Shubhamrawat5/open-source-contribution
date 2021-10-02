//Program to make a bank account in java using various loops

import java.util.*;

class Account
{
int accno;
String name;
float bal;
Account(int accno, String name,float bal)
{
this.accno= accno;//this:ref of var
this.name=name;
this.bal=bal;
}
}


public class expt4
{
public static void main(String[] args)
{
int ch,i;
Scanner sc = new Scanner(System.in);
System.out.println("Enter the number of customers:");
int customer = sc.nextInt();
Account ac[]= new Account[customer];//array of object 
System.out.println("Enter the intial number of accounts to be added:");
int ni = sc.nextInt();
int n1 = ni;
if(ni<=customer)
{
for(i=0;i<ni;i++)//accepting info in array of obj
{
System.out.println("Enter Account Number:");
int accno = sc.nextInt();
System.out.println("Enter Account Holder Name:");
String name = sc.next();
System.out.println("Enter Balance:");
float bal = sc.nextInt();
ac[i] = new Account(accno,name,bal);
}
do{

System.out.println("");
System.out.println("Enter a valid choice:");
System.out.println("1.Add Account");
System.out.println("2.Delete Account");
System.out.println("3.Display Account:");
System.out.println("4.Exit");
ch= sc.nextInt();
System.out.println("");
switch(ch)
{

case 1: if (ni>= customer)//ni:initial customers 
{
System.out.println("Number of customers is already maximum!!Cant add more accounts");
}
else
{
if(ni>=n1)
{
System.out.println("Enter the Account Number:");
int accno= sc.nextInt();
System.out.println("Enter the Account Holder Name:");

String name = sc.next();
System.out.println("Enter the Balance in the account:");
float bal = sc.nextInt();
ac[ni++]= new Account(accno,name,bal);//creating an object

}
else
{
System.out.println("Enter Account Number:");
int accno = sc.nextInt();
System.out.println("Enter Account Holder Name:");
String name = sc.next();
System.out.println("Enter Balance in the account:");
float bal = sc.nextInt();
ac[ni].accno = accno;// case when we delete an acc.The obj is already made so no need to make one more and directly store
ac[ni].name= name;
ac[ni].bal= bal;
ni++;
}
}
break;
case 2: int count =0;
System.out.println("Enter Account Number to be deleted:");
int daccno = sc.nextInt();
for(i=0;i<ni;i++)
{
if(daccno==ac[i].accno)
{
for(int j =i;j<(ni-1);j++)
{
ac[j]= ac[j+1];
}
ni--;
count=1;
System.out.println("Account Deleted");
}

}
if(count!=1)
{
System.out.println("No such Account Exists.");
}
break;


case 3:
System.out.println("");
for(i=0;i<ni;i++)
{
System.out.println("account number:"+ac[i].accno+"\n account name "+ac[i].name+"\n account balance:"+ac[i].bal);
}

System.out.println("");
break;



case 4:
System.out.println("----------------------END--------------------------");
break;
default:
System.out.println("Invalid Option.Try Again");
break;
}

}while(ch!=4);
}
else
{
System.out.println("The accounts cannot exceed number of customers");
}

}
}

