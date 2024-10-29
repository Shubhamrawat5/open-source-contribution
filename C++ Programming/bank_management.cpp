// Write a program in C++ to define a class named Bank.
// Include the following data members:-
// a. Name of account holder b. Account number c. type
// of account d. balance amount in account
// e. number of transactions in the bank(static data member)
// Create the following member functions:-
// i. To read inputs ii. To deposit an amount
// To withdraw amount after checking current balance

#include <iostream>
using namespace std;

class Bank
{
private:
    string name;
    int acc_no;
    string acc_type;
    float balance;
    static int transactions;

public:
    void read()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> acc_no;
        cout << "Enter account type: ";
        cin >> acc_type;
        cout << "Enter balance: ";
        cin >> balance;
    }
    void deposit()
    {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        transactions++;
        cout<<amount<<" deposited successfully"<<endl;
    }
    void withdraw()
    {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance -= amount;
            transactions++;
            cout<<amount<<" withdrawn successfully"<<endl;
        }
    }
    static int display_transactions()
    {
        return transactions;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account number: " << acc_no << endl;
        cout << "Account type: " << acc_type << endl;
        cout << "Balance: " << balance << endl;
        cout << "Number of transactions: " << display_transactions() << endl;
    }
    void display_balance()
    {
        cout<<"Balance: "<<balance<<endl;
    }
};

int Bank::transactions = 0;

int main()
{
    Bank b;
    int choice;
    b.read();
    b.display();
    while(choice!=5)
    {
        cout<<"1. Deposit\n"<<"2. Withdraw\n"<<"3. Balance\n"<<"4. Transactions\n"<<"5. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            b.deposit();
            break;
        case 2:
            b.withdraw();
            
            break;
        case 3:
            b.display_balance();
            break;
        case 4:
            cout<<"Number of transactions: "<<b.display_transactions()<<endl;
            break;
        case 5:
            cout<<"Exiting......."<<endl; 
            break;   
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    return 0;
}