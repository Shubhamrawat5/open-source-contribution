//To checkout the problem statement, visit
//https://www.hackerrank.com/challenges/java-loops/problem
//contributed by AnuragYadav365

import java.util.*;
import java.io.*;

class Loop_Series{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            //loops upto n-1 becuase we need sum upto n-1 terms
            for(int x = 0; x<n; x++){
                //calculating the value of next Term 
                int next_term = (int) ((Math.pow(2, x)) * b);

                //adding the next tem with previously calculated value
                a = a + next_term;
                System.out.print(a + " ");
            }
            System.out.println();
        }
        in.close();
    }
}

