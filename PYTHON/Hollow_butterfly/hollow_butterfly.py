n=int(input("Enter the no. or rows:"))
for i in range (1,n):
    for j in range (1,2*n+2):
        if j==1 or j==2*n or j==i or j==(2*n+1)-i:
            print("*",end=" ")
        else :
            print(" ",end=" ")    
    print() 
for i in range (n,n+1):
    for j in range(1,2*n+1):
        if j==1 or j==2*n or j==n or j==n+1:
            print("*",end=" ")
        else:
            print(" ",end=" ")
    print()
for i in range (n-1,0,-1):
    for j in range (1,2*n+2):
        if j==1 or j==2*n or j==i or j==(2*n+1)-i:
            print("*",end=" ")
        else :
            print(" ",end=" ")  
    print()