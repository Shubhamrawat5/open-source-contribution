import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class JavaCollectionExample {
  public static void main(String[] args) {
    System.out.println("\nInput Names with commas without space to continue then press enter \n******User Names:*****");
    Scanner scanner = new Scanner(System.in);
    String nameListString = scanner.nextLine();

    User user = new User();
    user.setUserNamesToList(nameListString);

    scanner.close();

  }
}

class User {

  public void setUserNamesToList(String nameList) {

    List<String> userNameList = new ArrayList<>(Arrays.asList(nameList.split(",")));

    Iterator<String> itr = userNameList.iterator();

    System.out.println("User List is: \n\n");

    while (itr.hasNext()) {
      System.out.println(itr.next());
    }

  }
}