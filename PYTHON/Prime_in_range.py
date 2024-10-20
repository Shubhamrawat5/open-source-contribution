def print_primes_in_range(A, B):
    for number in range(A,B+1):
        
        if number<=1:
            print("",end="")
        else:
            for j in range(2,int(number**0.5+1)):
                if number%j ==0:
                    break
            else:
                print(number, end=" ")
