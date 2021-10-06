import java.io.*;
import java.util.*;
/*
This code will print maximum sum of hour glass in a given 2D matrix
*/

public class HourGlass {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int max =Integer.MIN_VALUE;
        int sum =0;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the Size of the Matrix: ");
        int size = scan.nextInt();
        List<List<Integer>> arr = new ArrayList<>();

        for (int i = 0; i < size; i++) {
            String[] arrRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> arrRowItems = new ArrayList<>();

            for (int j = 0; j < size; j++) {
                int arrItem = Integer.parseInt(arrRowTempItems[j]);
                arrRowItems.add(arrItem);
            }

            arr.add(arrRowItems);
        }

        for (int i = 0; i < arr.size()-2; i++) {
            for (int j = 0; j < arr.size()-2; j++) {

                sum = arr.get(i).get(j) + arr.get(i).get(j+1) +arr.get(i).get(j+2) +
                arr.get(i+1).get(j+1) + 
                arr.get(i+2).get(j) +arr.get(i+2).get(j+1) +arr.get(i+2).get(j+2);

                if(max<sum){
                    max=sum;
                }
            }
        }
        System.out.println(max);

        bufferedReader.close();
    }
} 