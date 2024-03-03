import random
import string

def generate_password(length, include_uppercase=False, include_symbols=True, include_numbers=True):
    password_characters = string.ascii_lowercase
    if include_uppercase:
        password_characters += string.ascii_uppercase
    if include_symbols:
        password_characters += string.punctuation
    if include_numbers:
        password_characters += string.digits

    password = ''.join(random.choice(password_characters) for _ in range(length))

    # Ensure at least one character of each type is included
    if include_uppercase:
        password = password[:random.randint(0, length-3)] + random.choice(string.ascii_uppercase) + password[random.randint(0, length-2):]
    if include_symbols:
        password = password[:random.randint(0, length-3)] + random.choice(string.punctuation) + password[random.randint(0, length-2):]
    if include_numbers:
        password = password[:random.randint(0, length-3)] + random.choice(string.digits) + password[random.randint(0, length-2):]

    return password

def main():
    print("Welcome to the PyPassword Generator!")

    while True:
        try:
            num_passwords = int(input("How many passwords would you like to generate?\n"))
            password_length = int(input("Enter the length of the password:\n"))
            include_uppercase = input("Include uppercase letters? (yes/no): ").lower() == "yes"
            include_symbols = input("Include symbols? (yes/no): ").lower() == "yes"
            include_numbers = input("Include numbers? (yes/no): ").lower() == "yes"

            for _ in range(num_passwords):
                password = generate_password(password_length, include_uppercase, include_symbols, include_numbers)
                print(f"Generated Password: {password}")
            
            another_generation = input("Generate more passwords? (yes/no): ").lower()
            if another_generation != "yes":
                break
        except ValueError:
            print("Invalid input. Please enter a valid number.")

if __name__ == "__main__":
    main()
