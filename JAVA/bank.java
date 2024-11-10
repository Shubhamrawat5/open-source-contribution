import java.util.*;

public class bank {
    public static class Account {
        public static double monthlyinterst(double IR, double P) {
            double Amount = P;
            Amount += ((P * IR) / 12) / 100;
            return Amount;
        }

        public static double yearlyinterest(double IR, double P) {
            double annualInterest = P;
            annualInterest += (IR * P) / 100;
            return annualInterest;
        }

        public static void modefi(double newRate, double P1) {
            System.out.println("The New Interest Rate is : " + newRate);
            Account.monthlyinterst(newRate, P1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the annual Interest rate : ");
        double rate = sc.nextDouble();
        System.out.print("Enter the amount of Person : ");
        double p = sc.nextDouble();
        double mamt = Account.monthlyinterst(rate, p);
        System.out.println("Amount after adding Monthly interest : " + mamt);
        double yamt = Account.yearlyinterest(rate, p);
        System.out.println("Amount after adding Yearly interest : ");
        System.out.println("Do you want to modefied interest Rate : ");
        String s = sc.next();
        if (s.equalsIgnoreCase("yes")) {
            System.out.print("Enter the interest rate : ");
            double newRate = sc.nextDouble();
            Account.modefi(newRate, p);
            System.out.println("The Monthly Interest is : ");
            Account.modefi(newRate, p);
        }
        System.out.print("Anunal Return : " + yamt);

        sc.close();
    }
}