//Program to P to verify whether his credit card numbers are valid or not. A valid credit card
//from ABC Bank has the following characteristics:
//● It must start with a 4,5 or 6 .
//● It must contain exactly 16 digits.
//● It must only consist of digits (0-9).
//● It may have digits in groups of 4, separated by one hyphen ‘-’


import re
num= input("enter your credit card number:")
print(len(num))
if re.search(r'^[456]+',num) and re.search(r'[\d]',num) and bool(re.se
arch(r'\s',num)) is False and bool (re.search(r'[az]',num)) is False and(bool(re.search(r'-
',num))is True and len(num)==19):
  print("The entered credit card number is valid")
else:
  print("The entered credit card number is invalid")
