#Savings calculator

#Personal details section
name = str(input("What is your name?: "))
place = str(input("Where do you live?"))
gender = str(input("Your gender (F =Female,M =Male,Any other letter=Custom)"))
age = int(input("What is your age? :")) 
currency = str(input("Which is your cuurency"))

#Output-Personal details   
print("*---USER PROFILE---*")

if gender == "F":
    print("Welcome Mrs."+name)
elif gender == "M":
    print("Welcome Mr."+name)
else :
    print("Welcome "+name)
print("You live in "+place)

print("Your age is : "+str(age))

if age < 18:
    print("You are a minor! Minors not allowed..!")
    exit()
elif age >= 18:
    print("You are an adult.Proceed to further steps.")


#Finacial details
hours_per_day = int(input("How many hours per day do you work ? : "))
pay_per_hour = int(input("How much do you get paid per hour ? : "))
days_per_week = int(input("How many days do you work per week ? : "))

expe_per_week = int(input("What is your weekly expenditure ? : "))
expe_per_month = int(input("What is your monthly expenditure ? : "))

hours_per_week = hours_per_day * days_per_week
pay_per_day = hours_per_day * pay_per_hour

pay_per_week = pay_per_day * days_per_week
pay_per_month = pay_per_week * 4

save_per_week = pay_per_week - expe_per_week
save_per_month = pay_per_month - expe_per_month


#Output-Financial details
print("*---FINANCIAL DETAILS---*")

print("You work "+str(hours_per_week)+"hours per week.")

print("Your daliy earnings are "+str(pay_per_day)+" "+currency+".")

print("Your weekly earnings are "+str(pay_per_week)+" "+currency+".")

print("Your monthly earnings are "+str(pay_per_month)+" "+currency+".")

print("Your weekly expenditure is "+ str(expe_per_week)+" "+currency+".")
