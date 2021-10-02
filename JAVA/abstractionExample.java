import java.util.Scanner;

class UniGrading {
    public static void main(String[] args) {

        String code;
        int marks;
        int attendance;

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter subject code and marks:");
        System.out.print("Subject code: ");
        code = sc.nextLine();
        System.out.print("Marks:");
        marks = sc.nextInt();
        System.out.print("Attendance marks:");
        attendance = sc.nextInt();

        UoKDemo student1 = new UoKDemo();

        student1.SubjectGrade(code, marks, attendance);

        sc.close();

    }
}

abstract class Grading {
    abstract void SubjectGrade(String subCode, int marks, int attendance);
}

class UoKDemo extends Grading {

    @Override
    void SubjectGrade(String subCode, int marks, int attendance) {
        //subject Grading depends on the subject list specified for a particular university
        //So this method can be overridden in different uni systems as per need

        String grade;

        char credit = (subCode.charAt(subCode.length() - 1));

        System.out.println("credit: " + credit);

        switch (credit) {
            case '1': {//This is a practical subject,so the grade is pass or fail
                if (marks >= 50) grade = "pass";
                else grade = "fail";
                break;
            }

            case '2': {//normal grading way
                if (0 < marks && marks < 20) {
                    grade = "S";
                } else if (20 <= marks && marks < 40) {
                    grade = "C";
                } else if (40 <= marks && marks < 60) {
                    grade = "B";
                } else if (60 <= marks && marks < 80) {
                    grade = "A";
                } else if (80 <= marks && marks <= 100) {
                    grade = "A+";
                } else grade = "Invalid marks";
                break;
            }

            case '3': {//compulsory courses: attendance marks considered
                marks = marks + attendance;
                //now grade normally
                if (0 < marks && marks < 20) {
                    grade = "S";
                } else if (20 <= marks && marks < 40) {
                    grade = "C";
                } else if (40 <= marks && marks < 60) {
                    grade = "B";
                } else if (60 <= marks && marks < 80) {
                    grade = "A";
                } else if (80 <= marks && marks <= 100) {
                    grade = "A+";
                } else grade = "Invalid marks";
                break;
            }

            default:
                grade = "Invalid Subject Code";
        }

        System.out.println("Grade: " + grade);

    }
}

