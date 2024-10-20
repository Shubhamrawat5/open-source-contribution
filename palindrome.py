def isPalindrome(N):
    n1=N
    n2=0
    while N>0:
        r=N%10
        n2= n2*10+r
        N=N//10
    if n1==n2:
        return True
    else:
        return False