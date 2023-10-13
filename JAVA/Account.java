import java.util.*;

 // Compiler version JDK 11.0.2

class Account
{
  int acc;
  String name;
  float amount;
  
  void insert (int a, String s, float amt)
  {
    acc=a;
    name=s;
    amount=amt;
  }
  
  void deposit (float amt)
  {
    amount=amount+amt;
    System.out.println(amt+" deposited");
  }
  
  void withdrawal (float amt)
  {
    if(amount <amt)
    {
      System.out.println("Insufficient balance");
      
    }
    else
    {
      amount=amount -amt;
      System.out.println(amt+" Withdrawal");
    }
  }
  
  void checkBalance()
  {
    System.out.println("Balance is: "+amount);
  }
  
  void display()
  {
    System.out.println(acc+" "+name+" "+amount);
  }
  
  
}




 class TestAccount 
 {
   public static void main(String args[])
   {
     Account a1 = new Account ();
    a1.insert(12,"ak",200);
    a1.display();
   }
 }
