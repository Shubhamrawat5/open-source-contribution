import java.util.*;

public class DateToDay {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int day, month, year;
        System.out.println("Enter (dd mm yyyy) : ");
        day = sc.nextInt();
        month = sc.nextInt();
        year = sc.nextInt();
        int day_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // to check wheather the inputed year is a leap or not and make changes
        // according to it
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            day_in_month[2] = 29;
        }

        // check weather input is valid or not
        if (day < 1 || day > day_in_month[month]) {
            System.out.print("The Day must range for 1 - " + day_in_month[month]);
            return;
        }

        if (month < 1 || month > 12) {
            System.out.print("The Month must range from 1 - 12");
        }
        // total day passes in month also in year
        int passed_days = day;
        for (int i = 1; i < month; i++) {
            passed_days += day_in_month[i];
        }
        // total day till this year
        int total_days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + passed_days;
        int odd_day = total_days % 7;
        switch (odd_day) {
            case 0:
                System.out.println("Sunday");
                break;
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
        }
    }
}
