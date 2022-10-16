import re
"""
     A website requires the users to input username and password to register.
     Write a program to check the validity of password input by users.
     Following are the criteria for checking the password:
     1. At least 1 letter between [a-z]
     2. At least 1 number between [0-9]
     1. At least 1 letter between [A-Z]
     3. At least 1 character from [$#@]
     4. Minimum length of transaction password: 6
     5. Maximum length of transaction password: 12
     Your program should accept a sequence of comma separated passwords and will check them
     according to the above criteria. Passwords that match the criteria are to be printed,
     each separated by a comma.
     Example
     If the following passwords are given as input to the program:
     ABd1234@1,a F1#,2w3E*,2We3345
     Then, the output of the program should be:
     ABd1234@1
"""

value = []
passwords = [x for x in input("Enter the password: ").split(',')]
print(f"passwords: {passwords}")
for password in passwords:
     print(f'{password} length is {len(password)}')
     if len(password)<6:
          print(f"minimum length of password should be 6.\n ***")
          continue 
     if len(password)>12:
          print(f"maximum length of password should be 12.\n ***")
          continue
     if not re.search("[a-z]+", password):
          print(f"a-z characters not in the {password}.\n ***")
          continue
     if not re.search('[0-9]+', password):
          print(f"0-9 letters are not in {password}.\n ***")
          continue
     if not re.search('[A-Z]+', password):
          print(f"A-Z alphabets are not in {password}.\n ***")
          continue
     if not any(not c.isalnum() for c in password):
          print(f"symbols are not in {password}.\n ***")
          continue
     else:
          print("***")
          value.append(password)
     

print(f'Result: {", ".join(value)}')

"""
Output1:
---------------------------------------------------------
Enter the password: Udac!@323, @Fhguwewh123,Lalit@123
passwords: ['Udac!@323', ' @Fhguwewh123', 'Lalit@123']
Udac!@323 length is 9
***
 @Fhguwewh123 length is 13
maximum length of password should be 12.
 ***
Lalit@123 length is 9
***
Result: Udac!@323, Lalit@123
---------------------------------------------------------

Output2:
---------------------------------------------------------
Enter the password: ABd1234@1,a F1#,2w3E*,2We3345
passwords: ['ABd1234@1', 'a F1#', '2w3E*', '2We3345']
ABd1234@1 length is 9
***
a F1# length is 5
minimum length of password should be 6.
 ***
2w3E* length is 5
minimum length of password should be 6.
 ***
2We3345 length is 7
symbols are not in 2We3345.
 ***
Result: ABd1234@1
---------------------------------------------------------
"""