from tabulate import tabulate



contact_book=[]


def addContact():
    
    contact={}
    print()
    name=input("Enter contact name:")
    phone=input("Enter  phone Number:")
    email=input("Enter  email ID:")
    address=input("Enter address:")
    
   
    contact['name']=name
    contact['phone']=phone
    contact['email']=email
    contact['address']=address

    contact_book.append(contact)

    print("\nContact has been added successfully....")
def deleteContact():
    phone=input("Enter contact number you want to delete:")
    for i in contact_book:
       
        if i['phone']==phone:
            contact_book.remove(i)
            print("\nContact has been deleted successfully.....")
        else:
            print("\nThis phone number  does not exist in your contact book....")



def updateContact():
    old_phone=input("Enter contact number you want to update:")
    for i in contact_book:
       
        if i['phone']== old_phone:
            new_phone=input("Enter new phone number:")
            i['phone']=new_phone
            print("\nContact has been updated successfully.....")
        else:
            print("\nThis phone number  does not exist in your contact book....")


def display():

    if (len(contact_book)==0):
        print("\nNo Contacts found in a record....")
    else:
        print("\n--------------------------------------------------------------")
        print("\t\tAvailable Contacts in your Contact Book")
        print("--------------------------------------------------------------")
        data=[]
        head=['Name' , "Phone Number" , 'Email', 'Address']
        for i in contact_book:


             mydata=[i['name'] , i['phone'] , i['email'] , i['address']]
             data.append(mydata)
            
        print(tabulate(data,headers=head , tablefmt="grid"))
        
        


def findContact():
    
    name=input("Enter name of a contact you want to search:")
    data=[]
    head=['Name' , "Phone Number" , 'Email', 'Address']
    print("\n--------------------------------------------------------------")
    print("\t\tSearch results")
    print("--------------------------------------------------------------")
    for i in contact_book:
        
       
        if i['name']==name:
            
             
             mydata=[i['name'] , i['phone'] , i['email'] , i['address']]
             data.append(mydata)
  
   

    if (len(data)>0):        
      print(tabulate(data,headers=head , tablefmt="grid"))
    else:
        print("\nNo such results are found in a record....")




def menu():

    print("\t\tContact Book Management System\n")
    print("1.Add New Contact")
    print("2.Show Contacts")
    print("3.Update Contact")
    print("4.Search Contact")
    print("5.Delete Contact")
    print("6.Exit")




if __name__ == "__main__":
    
    start=True

    while start:
        print("\n--------------------------------------------------------------")
        menu()
        print("--------------------------------------------------------------")
        ch=input("Enter your choice:")

        if ch=='1':
             addContact()

        elif ch=='2':
            display()
            
          
        elif ch=='3':
            updateContact()
             
        elif ch=='4':
            findContact()

        elif ch=='5':
            deleteContact()
            
        elif ch=='6':
            print("Closing Program.......")
            print("Thank You")
            start=False
        else:
            print("\nInvalid input !!!")

