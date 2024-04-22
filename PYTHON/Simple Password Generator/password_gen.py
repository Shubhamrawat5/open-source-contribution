import random
import string


def generate_new_password(length):
    all=string.ascii_lowercase + string.ascii_uppercase + string.digits + "$@()"
    passwd=""
    if (length < 8 or length >16):
        print("Please enter length between 8-16....")
        
        
    else:
        passwd=passwd.join(random.sample(all,length))
        print(f"Your generated password is :{passwd}")



if __name__ == "__main__":
    run=True
    while run:
        print()
        print(10 * "-", "Welcome to Password Generator", 10 * "-")
        length=int(input("Enter length of a password to be generated (8-16):"))
        generate_new_password(length)
        choice=input("Do you want to generate a new password ? (y/n)")
        if choice=='n' or choice=="N":
            run=False

            



