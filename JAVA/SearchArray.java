import java.util.*;

public class SearchArray {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your size:");
        int size = sc.nextInt();
        int marks[] = new int[size];
        System.out.println("Enter your array:");
        for (int i = 0; i < size; i++) {
            marks[i] = sc.nextInt();
        }

        System.out.println("\nEnter your search element:");
        int search = sc.nextInt();
        for (int i = 0; i < size; i++) {
            if (marks[i] == search) {
                System.out.println("your output :");
                System.out.println(i);
            }

        }
    }

}
