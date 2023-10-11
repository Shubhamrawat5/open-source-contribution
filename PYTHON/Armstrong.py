
# to check whether the given number is armstrong or not
# without using power function

n = 123 # or n=int(input()) -> taking input from user
s = n # assigning input value to the s variable
b = len(str(n))
sum1 = 0


while n != 0:
	r = n % 10
	sum1 = sum1+(r**b)
	n = n//10
if s == sum1:
	print("The given number", s, "is armstrong number")
else:
	print("The given number", s, "is not armstrong number")

 
