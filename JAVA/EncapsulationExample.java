import java.util.Scanner;

public class EncapsulationExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\nPlease enter following details");

        System.out.print("Enter contact number: ");
        int contactNumber=scanner.nextInt();

        System.out.print("Enter first name: ");
        String firstName=scanner.next();

        System.out.print("Enter surname: ");
        String surName=scanner.next();

        System.out.print("Enter email: ");
        String email=scanner.next();

        System.out.print("Enter company: ");
        String company=scanner.next();

        System.out.print("Enter label: ");
        String label=scanner.next();

        UserContactDetails user = new UserContactDetails();
        user.setContactNumber(contactNumber);
        user.setFirstName(firstName);
        user.setSurName(surName);
        user.setEmail(email);
        user.setCompany(company);
        user.setLabel(label);

        System.out.println();
        System.out.println("User Details Preview");
        System.out.println("--------------------");
        System.out.println("Contact Number: "+ user.getContactNumber());
        System.out.println("First Name: "+ user.getFirstName());
        System.out.println("Surname: "+ user.getSurName());
        System.out.println("Email: "+ user.getEmail());
        System.out.println("Company: "+ user.getCompany());
        System.out.println("Label: "+ user.getLabel());

        scanner.close();
    }
}

class UserContactDetails{
    //contact no,first name,surname, email, company, label
    private int contactNumber;
    private String firstName;
    private String surName;
    private String email;
    private String company;
    private String label;

    public void setContactNumber(int contactNumber){
        this.contactNumber=contactNumber;
    }

    public int getContactNumber(){
        return this.contactNumber;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getSurName() {
        return surName;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getCompany() {
        return company;
    }

    public void setCompany(String company) {
        this.company = company;
    }

    public String getLabel() {
        return label;
    }

    public void setLabel(String label) {
        this.label = label;
    }
}


