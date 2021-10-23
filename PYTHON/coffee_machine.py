MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    },
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}

money = 0

machine_on = True


def are_enough_resources(type_of_beverage):
    for ingredient in resources:
        if resources[ingredient] < MENU[type_of_beverage]["ingredients"][ingredient]:
            print(f"Sorry, there is not enough {ingredient}.")
            return False
        else:
            return True


def process_payment(type_of_beverage):
    global money
    print("Please insert coins:")
    print("~~~~~~~~~~~~~~~~~~~~~")
    quarters = int(input("How many quarters? "))
    dimes = int(input("How many dimes? "))
    nickels = int(input("How many nickels? "))
    pennies = int(input("How many pennies? "))
    print("~~~~~~~~~~~~~~~~~~~~~")
    inserted_money = (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (pennies * 0.01)
    if inserted_money < MENU[type_of_beverage]["cost"]:
        print("Sorry that's not enough money. Money refunded.")
    else:
        difference = round(inserted_money - MENU[type_of_beverage]["cost"], 2)
        print(f"Here is your ${difference} in change.")
        money += MENU[type_of_beverage]["cost"]
        for ingredient in MENU[type_of_beverage]["ingredients"]:
            resources[ingredient] -= MENU[type_of_beverage]["ingredients"][ingredient]
        print(f"Here is your {type_of_beverage} ☕️. Enjoy!")


while machine_on:
    type_of_beverage = input("\tWhat would you like? (espresso/latte/cappuccino): ").lower()

    if type_of_beverage == "off":
        print("Shutting down...")
        machine_on = False
    elif type_of_beverage == "report":
        print("~~~~~~~~~~~~~~~~~~~~~")
        print(f"Water: {resources['water']}ml")
        print(f"Milk: {resources['milk']}ml")
        print(f"Coffee: {resources['coffee']}ml")
        print(f"Money: ${money}")
        print("~~~~~~~~~~~~~~~~~~~~~")
    elif type_of_beverage == "latte":
        if are_enough_resources(type_of_beverage) == True:
            process_payment(type_of_beverage)
    elif type_of_beverage == "cappuccino":
        if are_enough_resources(type_of_beverage) == True:
            process_payment(type_of_beverage)
    elif type_of_beverage == "espresso":
        if are_enough_resources(type_of_beverage) == True:
            process_payment(type_of_beverage)