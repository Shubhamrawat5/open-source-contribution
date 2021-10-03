//To checkout the problem statement, visit
//https://codeforces.com/problemset/problem/677/A
//contributed by AnuragYadav365

import java.util.Scanner;

public class Fence{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(); //number of friends
        int h = scan.nextInt(); //height of fence

        int road_width = 0;
        for(int i=0; i<n; i++){
            int a = scan.nextInt(); //scanning height of friends
            if(a>h){
                road_width+=2;
            }
            else if(a<=h){
                road_width++;
            }
        }
        scan.close();
        System.out.println(road_width);
    }
}