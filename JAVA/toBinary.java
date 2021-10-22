import java.util.Scanner;

public class toBinary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number: ");
        int num = sc.nextInt();
        System.out.println(toBinaryString(num));
    }
    public static String toBinaryString(int decimal) {
        String binary = "";
        if (decimal == 0) {
            binary = "0";
            decimal = 0;
        }
        while (decimal != 0) {
            binary = (decimal % 2) + binary;
            decimal /= 2;
        }
        return binary; 
    }
}
