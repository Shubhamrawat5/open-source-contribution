import java.util.*;

public class VotingIlligiblity {
    public static void eligibility(int age) {
        if (age >= 18) {
            System.out.println("Your r eligiable to vote.");
        } else {
            System.out.println("You r not eligiable to vote.");
        }
        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();
        eligibility(age);
    }

}
