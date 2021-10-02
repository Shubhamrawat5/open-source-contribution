import java.util.Scanner;

public class JavaEncapsulationExample {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // scanner instance

    UserDetails userDetails = new UserDetails();

    System.out.print("\nEnter first name: ");
    userDetails.setFirstName(scanner.next()); // set user details

    System.out.print("\nEnter last name: ");
    userDetails.setLastName(scanner.next()); // set user details

    System.out.print("\nEnter email: ");
    userDetails.setEmail(scanner.next()); // set user details

    System.out.print("\nEnter age: ");
    userDetails.setAge(scanner.nextInt()); // set user details

    System.out.print("\nUser full details: \n"); // now get user details

    System.out.print("First Name: " + userDetails.getFirstName() + "\nLast Name: " + userDetails.getLastName()
        + "\nAge: " + userDetails.getAge() + "\nEmail: " + userDetails.getEmail() + "\n");

    scanner.close();
  }
}

// encapsuled java class
class UserDetails {
  // private variables

  private String firstName;

  private String lastName;

  private String email;

  private int age;

  public void setFirstName(String userFirstName) {
    firstName = userFirstName;
  }

  public String getFirstName() {
    return firstName;
  }

  public void setLastName(String userLastName) {
    lastName = userLastName;
  }

  public String getLastName() {
    return lastName;
  }

  public void setEmail(String userEmail) {
    email = userEmail;
  }

  public String getEmail() {
    return email;
  }

  public void setAge(int userAge) {
    age = userAge;
  }

  public int getAge() {
    return age;
  }

}
