//Program to make a calculator using inheritance

import java.util.Scanner;
//inheritance implementation
class A {
    int a, b, c, sum,diff,product,div,rem;
    Scanner sc = new Scanner(System.in);
    void input() {
        System.out.print("Enter number 1 :");
        a = sc.nextInt();
System.out.print("Enter number 2 :");
        b = sc.nextInt();
        
    }
}

class B extends A {

    void add() {
        sum = a + b ;
        System.out.println("\n The sum is:"+sum+"\n");
    }
    void pro()
    {
      product=a*b;
       System.out.println("The product is:"+product+"\n");
    }
    void differnce()
    {
      diff=a-b;
       System.out.println("The difference is :"+diff+"\n");
    }
   void division()
    {
      div=a/b;
      rem=a%b;
       System.out.println("The quotient is :"+div);
System.out.println("The remainder is :"+rem);
    }


    public static void main(String args[]) {
        B obj = new B();
        obj.input();
        obj.add();
        obj.pro();
        obj.differnce();
        obj.division();
    }
}
