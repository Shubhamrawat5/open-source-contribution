//To checkout the problem statement, visit
//https://www.hackerrank.com/challenges/java-currency-formatter/problem
//contributed by AnuragYadav365

import java.util.*;
import java.text.*;

public class Currency_converter {
    
    public static void main(String[] args) throws ParseException {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();

        // Write your code here.
        NumberFormat nf1 = NumberFormat.getCurrencyInstance(Locale.US);
        NumberFormat nf3 = NumberFormat.getCurrencyInstance(Locale.CHINA);
        NumberFormat nf4 = NumberFormat.getCurrencyInstance(Locale.FRANCE);
        NumberFormat nf2 = NumberFormat.getCurrencyInstance(new Locale("en", "in"));

        System.out.println("US: " + nf1.format(payment));
        System.out.println("India: " + nf2.format(payment));
        System.out.println("China: " + nf3.format(payment));
        System.out.println("France: " + nf4.format(payment));
        System.out.println();
    }
}
