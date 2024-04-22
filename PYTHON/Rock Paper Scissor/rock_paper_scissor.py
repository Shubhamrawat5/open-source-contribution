import random

def menu():
    print(20*"-","Rock paper Scissor",20*"-")
    print("1.play")
    print("2.exit")

def play():
    p_score=0
    c_score=0
    play='y'
    while play=='y':
        user=input("\nEnter your choice['rock','paper','scissor']:")
        computer=random.choice(['rock','paper','scissor'])
        print(f"\nuser choice: {user} || computer choice: {computer}")
        if user == computer:
            print("Tie!")
        elif user=="rock":
            if computer=="scissor":
                p_score+=1
                print("\nuser wins!!!")
            else:
                c_score+=1
                print("\nComputer wins!!!")
        elif user=="paper":
            if computer=="rock":
                p_score+=1
                print("\nuser wins!!!")
            else:
                c_score+=1
                print("\nComputer wins!!!")
        elif user=="scissor":
            if computer=="paper":
                p_score+=1
                print("\nuser wins!!!")
            else:
                c_score+=1
                print("\nComputer wins!!!")
        else:
            print("\nPlease enter choice between['rock','paper','season']")
            print("\nNeed to restart program again....")
            exit()
        print(f"\nplayer score:{p_score} || computer score:{c_score}")
        print(30*"__")
        play=input("\nDo you want to play continue(y/n)?:")
        print("\n"+30*"**")

def main():
    menu()
    print(30*"__")
    ch=input("Enter your choice:")
    print(30*"__")
    if ch=="1":
        play()
    elif ch=="2":
        exit()
    else:
        print("\ninvalid input...")
        print("Need to restart program again....")

main()