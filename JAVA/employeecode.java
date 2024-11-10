import java.util.*;

public class employeecode {
    public static class Employee {
        String name;
        int age;
        double salary;

        public Employee(String name, int age, double salary) {
            this.name = name;
            this.age = age;
            this.salary = salary;
        }

        public String getName() {
            return name;
        }

        public int getage() {
            return age;

        }

        public void setage(int age) {
            this.age = age;
        }

        public double getsalary() {
            return salary;
        }

        public void setsalary(double salary) {
            this.salary = salary;
        }

        public void raisesalary() {
            this.salary += this.salary * 0.1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the employee's name:");
        String name = scanner.nextLine();

        System.out.println("Enter the employee's age:");
        int age = scanner.nextInt();

        System.out.println("Enter the employee's salary:");
        double salary = scanner.nextDouble();

        Employee emp = new Employee(name, age, salary);

        System.out.println("Employee Details:");
        System.out.println("Name: " + emp.getName());
        System.out.println("Age: " + emp.getage());
        System.out.println("Salary: " + emp.getsalary());

        emp.raisesalary();

        System.out.println("\nName: " + emp.getName());
        System.out.println("Age: " + emp.getage());
        System.out.println("After 10% raise:");
        System.out.println("Salary: " + emp.getsalary());

        scanner.close();
    }
}