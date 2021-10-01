#include <stdio.h>

/*
 * function: validateDate
 * arguments: d- day, m- month, y- year
 * return type: 0 - invalid, 1 - valid
 * */
int validateDate(int d, int m, int y)
{
    //check year validity
    if (y >= 1800 && y <= 2999) {
        //check month validity
        if (m >= 1 && m <= 12) {
            //check day validity
            if (d >= 1 && d <= 31) {
                if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                    return 1; //valid date
                else if ((d >= 1 && d <= 30) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                    return 1; //valid date
                else if ((d >= 1 && d <= 28) && (m == 2))
                    return 1; //valid date
                else if (d == 29 && m == 2 && ((y % 400 == 0) || (y % 4 == 0 && y % 4 != 0)))
                    return 1; //valid date
                else
                    return 0; //invalid day
            }
            else {
                printf("\nTHERE IS NO SUCH MONTH DATE SO ADD CAREFULLY");
                return 0; //day is invalid
            }
        }
        else {
             printf("\nTHERE ARE ONLY 12 MONTHS AS PER NOW SO JUST ADD DATE WITHIN IT");
            return 0; //month is invalid
        }
    }
    else {
        printf("\nPLZ ENTER YEAR FROM 1800 TO 2999");
        return 0; //year is invalid
    }
}
// This function will return week day number from 0 to 6
int wd(int year, int month, int day)
{
    int wday = 0;
    wday = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
               + (365 * (year + 4800 - ((14 - month) / 12)))
               + ((year + 4800 - ((14 - month) / 12)) / 4)
               - ((year + 4800 - ((14 - month) / 12)) / 100)
               + ((year + 4800 - ((14 - month) / 12)) / 400)
               - 32045)
        % 7;
    return wday;
}

int main()
{
    int day, month, year;
    int wDayNo = 0;
    char dayNames[][12] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    //input date
    printf("Input date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &day, &month, &year);

    //check date is correct or not
    if (validateDate(day, month, year) == 1) {
        printf("Date is correct [%02d/%02d/%02d].\n", day, month, year);
        //get weekday number
        wDayNo = wd(year, month, day);
        //print weekday according to wDayNo
        printf("week day is: %s\n", dayNames[wDayNo]);
    }
    else
        printf("\nDate is in-correct.\n");

    return 0;
}