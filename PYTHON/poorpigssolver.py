import math

def poorPigs(buckets, minutesToDie, minutesToTest):
    pigs = 0
    while (minutesToTest / minutesToDie + 1) ** pigs < buckets:
        pigs += 1
    return pigs

buckets = int(input("Enter the number of buckets: "))
minutesToDie = int(input("Enter the number of minutes it takes for a pig to die: "))
minutesToTest = int(input("Enter the number of minutes for a test: "))

result = poorPigs(buckets, minutesToDie, minutesToTest)
print("The minimum number of pigs needed:", result)
