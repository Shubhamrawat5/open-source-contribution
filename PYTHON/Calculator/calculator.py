def addition(a , b):
    return a+b

def subtract(a,b):
    return a-b

def multiplication(a,b):
    return a*b

def division(a,b):

    try:

        return a/b
    except Exception as e:
         return f"Cannot perform operation due to  '{e}' error"
    



def menu():
  
    print("\n\t\tBasic Calculator")
    print("1.Addition")
    print("2.Subtraction")
    print("3.Multiplication")
    print("4.Division")
    print("5.Exit")




if __name__ == "__main__":
    run=True 

    while run:
        menu()
        ch=input("Enter operation you want to perform :")
        
        if ch=='1':
            num1=int(input("Enter value 1:"))
            num2=int(input("Enter value 2:"))
            print(f"Result:{addition(num1,num2)}")

        elif ch=='2':
            num1=int(input("Enter value 1:"))
            num2=int(input("Enter value 2:"))
            print(f"Result :{subtract(num1, num2)}")
        elif ch=='3':
            num1=int(input("Enter value 1:"))
            num2=int(input("Enter value 2:"))
            print(f"Result :{multiplication(num1, num2)}")
        elif ch=='4':
            num1=int(input("Enter value 1:"))
            num2=int(input("Enter value 2:"))
            print(f"Result :{division(num1, num2)}")
        elif ch=='5':
            print("Closing Program.......")
            print("Thank You")
            run=False
        else:
            print("Invalid input !!!")
        