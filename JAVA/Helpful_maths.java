//To checkout the problem statement, visit
//https://codeforces.com/problemset/problem/339/A
//contributed by AnuragYadav365

import java.util.Scanner;

public class Helpful_maths {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();

        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '+'){
                continue;
            }
            else if(s.charAt(i) == '1'){
                count1+=1;
            }

            else if(s.charAt(i) == '2'){
                count2+=1;
            }

            else if(s.charAt(i) == '3'){
                count3+=1;
            }
        }

        //System.out.println("Total count is: " + count1 + count2 + count3);

        String finalString = "1+".repeat(count1)+"2+".repeat(count2)+"3+".repeat(count3);
        System.out.println(finalString.substring(0, finalString.length()-1));
    }
}
