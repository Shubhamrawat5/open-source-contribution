   
#include "iostream"
#include "cctype"
#include "string.h"
#include "cstdlib"

using namespace std;

void rules()
{
	cout<<"\t\t\t\t\tRules of the Game are\n";
	cout<<"\t\t\t\t\t**********************\n\n";
	cout<<"1. You have to choose a number between 1 to 10\n";
	cout<<"2. Then the dice will be rolled and if the number on the\n";
	cout<<"   dice is same as the choosen number, then You WIN\n";
	cout<<"3. Winner will get 10 times of the money\n";
	cout<<"4. Else you will lose the amount you bet\n\n";
	cout<<"We wish you a very good luck!!!\n\nLet's Begin the Game\n\n";
}

main()
{
	int n,dice,balance,bet;
	char name[30],c;
	cout<<"\t\t\t\t\tWelcome to Casino\n";
	cout<<"\t\t\t\t\t*****************";
	cout<<"\n\nPlease Enter your Name: ";
	gets(name);
	strupr(name);
	cout<<"Enter the Balance to play the game: ";
	cin>>balance;
	cout<<"\n\n\n";
	do
	{
		rules();
		cout<<"Hello "<<name<<", Your current Balance is: Rs"<<balance<<endl;
		
		do
		{
			cout<<"Please Enter the amount to Bet: ";
			cin>>bet;
			if(bet>balance)
			{
				cout<<"Sorry! Betting Amount can't be more than the Balance\n";
				cout<<"Please Re-enter your Bet Amount: ";
			}
		}while(bet>balance);
		cout<<"\nChoose a number between 1 to 10: ";
		cin>>n;
		cout<<"\n\nRolling Dice...\n\n";
		dice=rand()%10+1;
		if(n==dice)
		{
			cout<<"Congratulations! You Win\n\n";
			balance*=10;
			cout<<"Your Current Balance is: Rs"<<balance;
		}
		else
		{
			cout<<"Better Luck Next Time!";
			balance-=bet;
			cout<<"Your Current Balance is: Rs"<<balance;
		}
		cout<<"\n\nThe Winning Number was: "<<dice;
		cout<<"\n\n"<<name<<" your current balance is Rs"<<balance;
		
		if(balance==0)
		{
			cout<<"Sorry! You have no money to play.";
			break;
		}
		
		cout<<"\n\nDo you wish to Play Again? (Y/N)\n";
		cin>>c;
	}while(c=='Y' || c=='y');
	cout<<"\n\n\nThank You for playing the game. Your Balance is Rs"<<balance;
	return 0;
}
