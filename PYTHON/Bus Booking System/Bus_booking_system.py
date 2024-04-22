class train:
    seats=15
    def book_ticket(self ):
        ch=input("Choose your destination:")
        if ch=='1':
             print(f"Your ticket is booked.\n your seat number is {self.seats}")
             print("You have to pay 70rs")
             self.seats=self.seats-1
        elif ch == '2':
            print(f"Your ticket is booked.\n your seat number is {self.seats}")
            print("You have to pay 300rs")
            self.seats=self.seats-1
        elif ch == '3':
            print(f"Your ticket is booked.\n your seat number is {self.seats}")
            print("You have to pay 80rs")
            self.seats=self.seats-1
        elif ch == '4':
            print(f"Your ticket is booked.\n your seat number is {self.seats}")
            print("You have to pay 250rs")
            self.seats=self.seats-1
        else:
            print("Invalid input")

    def get_seats(self):
        print(f"number of seats available is {self.seats}")
    def get_fare_info(self):
        print("Welcome to Dehradun ISBT")
        print("1.Dehradun to Haridwar     70rs")
        print("2.Dehradun to Delhi        300rs")
        print("3.Dehradun to Rishikesh     80rs")
        print("4.Dehradun to kotdwar       250rs")


t1=train()

t1.get_seats()
print(10*"----")
t1.get_fare_info()
print(10*"----")
t1.book_ticket()
print(10*"----")
t1.get_seats()
print(10*"----")
t1.book_ticket()
print(10*"----")
t1.get_seats()
print(10*"----")
t1.book_ticket()
print(10*"----")
t1.get_seats()
print(10*"----")
