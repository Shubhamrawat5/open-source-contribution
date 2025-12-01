import java.util.Scanner;

public class Deletion {
    public static void main(String[] args) {
        int n, x, flag =1, loc =0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no. of elements you want in array ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter all elements ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the element you want to delete ");
        x= sc.nextInt();
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                flag = 1;
                loc = i;
                break;
            }
            else{
                flag= 0;
            }

        }
        if (flag == 1) {
            for (int i = loc+1; i < n; i++) {
                arr[i -1] = arr[i];
            }
            System.out.println("After deletion");
            for (int i = 0; i < n-2; i++) {
                System.out.print(arr[i]+ " ");

            }
            System.out.println(arr[n-2]);
        }
        else{
            System.out.println("Element not found");
        }
    }
}
