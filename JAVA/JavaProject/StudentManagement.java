package open-source-contribution.JAVA.JavaProject;

// Description: A console-based application for managing student details like name, age, grade, and subjects. Key Features:

// Add, delete, and update student information
// Search for students by name
// Display all student details
import java.util.ArrayList;
import java.util.Scanner;

class Student {
    String name;
    int age;
    double grade;

    Student(String name, int age, double grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    @Override
    public String toString() {
        return "Student{" + "name='" + name + '\'' + ", age=" + age + ", grade=" + grade + '}';
    }
}

class StudentManagementSystem {
    private final ArrayList<Student> students = new ArrayList<>();

    void addStudent(String name, int age, double grade) {
        students.add(new Student(name, age, grade));
        System.out.println("Student added: " + name);
    }

    void displayStudents() {
        for (Student student : students) {
            System.out.println(student);
        }
    }
}

public class StudentManagement {
    public static void main(String[] args) {
        StudentManagementSystem sms = new StudentManagementSystem();
        sms.addStudent("Alice", 20, 85.5);
        sms.addStudent("Bob", 22, 90.0);
        sms.displayStudents();
    }
}
