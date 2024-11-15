
//This code update the bit value to "1" or "0" according to thr user input
import java.util.*;

public class UpdateBit {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter operation : ");
        int opr = sc.nextInt();
        System.out.print("Enter the number : ");
        int no = sc.nextInt();
        System.out.print("Enbter the positon : ");
        int pos = sc.nextInt();
        int bitMass = 1 << pos;
        if (opr == 1) {
            int newBit = bitMass | no;
            System.out.print("The Final number : " + newBit);
        } else {
            int notbitMass = ~bitMass;
            int newBit = notbitMass & no;
            System.out.print("The final number :" + newBit);
        }
    }
}
