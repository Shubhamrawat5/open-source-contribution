base = input("What is your base number(no fractions, only decimals): ") 
exp = input("What is your exponent(whole numbers only): ")
total = 0

base = float(base)
exp = int(exp)
total = float(total)

total = base

while exp != 1:
  total = total*base
  exp = exp - 1

print(total)
