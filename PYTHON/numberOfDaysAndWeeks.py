"""
Given a file with number of days as integers
write a program that returns the total number of weeks and days
from the integer value of days.
"""

def retrieveWeeksAndDays(num):
    if num == 7:
        weeks = 1
        return f"{weeks} week"
    elif num < 7:
        days = num
        return f"{days} days"
    elif num % 7 > 0 :
        days = num % 7
        weeks = num // 7
        return f"{weeks} weeks ,{days} days"
    else:
        weeks = num // 7
        return f"{weeks} weeks"


results = retrieveWeeksAndDays(7)
print(results)


