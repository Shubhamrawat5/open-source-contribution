
# Python program to check leap year or not
def checkYear(year):
    if (year % 4) == 0:
        if (year % 100) == 0:
            if (year % 400) == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False


# Driver Code
year = 2000
if (checkYear(year)):
    print("Leap Year")
else:
    print("Not a Leap Year")


# Leap year checker
'''
Python program to check if year is a leap year or not.
Author: Ayushi Rawat
'''

year = 1000

# To get year (integer input) from the user
# year = int(input("Enter the year: "))

if (year % 4) == 0:
   if (year % 100) == 0:
       if (year % 400) == 0:
           print("{0} is a leap year".format(year))
       else:
           print("{0} is not a leap year".format(year))
   else:
       print("{0} is a leap year".format(year))
else:
   print("{0} is not a leap year".format(year))

