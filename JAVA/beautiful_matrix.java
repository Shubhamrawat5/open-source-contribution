//To checkout the problem statement, visit
//https://codeforces.com/problemset/problem/263/A
//contributed by AnuragYadav365

import java.util.Scanner;

public class beautiful_matrix{
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        int rowpos = 0;
        int colpos = 0;
        int[][] arr = new int[5][5];

        // Getting elements stored in 2-D int array
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                arr[i][j] = inp.nextInt();
                //System.out.println("Element is " + arr[i][j]);

                //taking the row value and col value of the position of 1
                if(arr[i][j] == 1){
                    rowpos=i;
                    colpos=j;
                }
            }
        }

        int count = 0;
        //Calculating steps required by 1 to get to middle i.e. at 3,3
        //if 1 at row 0 or row 4, move 2 steps
        if(rowpos == 0 || rowpos == 4){
            count = count+2;
            //if col = 0 or 4, move 2
            if(colpos == 0 || colpos == 4){
                count = count+2;
            }
            //if col = 1 or 3, move 1
            else if(colpos == 1 || colpos == 3){
                count = count+1;
            }
        }

        //if row = 1 or 3, move 1 step
        else if(rowpos == 1 || rowpos == 3){
            count = count+1;
            if(colpos == 0 || colpos == 4){
                count = count+2;
            }
            else if(colpos == 1 || colpos == 3){
                count = count+1;
            }
        }
        //then it must be at row = 2
        else{
            if(colpos == 0 || colpos == 4){
                count = count+2;
            }
            else if(colpos == 1 || colpos == 3){
                count = count+1;
            }
        }
        System.out.println(count);

        inp.close();
    }
}