# Python program to demonstrate
# symmetry and palindrome of the string

  
# Function to check whether the string is palindrome or not
def palindrome(a):
  
    # finding the mid, start and last index of the string
    mid = (len(a)-1)//2     #you can remove the -1 or you add <= sign in line 21 
    start = 0                #so that you can compare the middle elements also.
    last = len(a)-1
    flag = 0
 
    # A loop till the mid of the string
    while(start <= mid):
  
        # comparing letters from right, from the letters from left
        if (a[start]== a[last]):
             
            start += 1
            last -= 1
        else:
            flag = 1
            break;
             
    # Checking the flag variable to check if the string is palindrome or not
    if flag == 0:
        print("The entered string is palindrome")
    else:
        print("The entered string is not palindrome")
         
# Function to check whether the string is symmetrical or not 
def symmetry(a):
     
    n = len(a)
    flag = 0
     
    # Check if the string's length is odd or even
    if n%2:
        mid = n//2 +1
    else:
        mid = n//2
        start1 = 0
    start2 = mid
     
    while(start1 < mid and start2 < n):
         
        if (a[start1]== a[start2]):
            start1 = start1 + 1
            start2 = start2 + 1
        else:
            flag = 1
            break
      
    # Checking the flag variable to check if the string is symmetrical or not
    if flag == 0:
        print("The entered string is symmetrical")
    else:
        print("The entered string is not symmetrical")
         
# Driver code
string = 'amaama'
palindrome(string)
symmetry(string)