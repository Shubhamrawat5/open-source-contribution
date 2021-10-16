import random
# Taking Input
t = input("Hello!, Want to play game?(yes/no):" )

x = random.randint(1, 10)
chance = 3
if t=="yes":
    print("You will get three chance to get it right.")
    print("Guess a number between 1 to 10")
    for i in range(3):
        y = int(input())
        if x==y:
            print("Congratulations! You win!!")
            break
        else:
            print("Try again!")
            print("Chances left:" + str(2-i))
        if x != y and 2-i==0:
            print("Sorry, You lost!")
else:
    print("Hope you liked it!")
    
