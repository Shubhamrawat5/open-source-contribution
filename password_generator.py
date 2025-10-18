import random
import string

def generate_password(length=12):
    """Generate a random secure password."""
    if length < 6:
        raise ValueError("Password length should be at least 6 characters.")

    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

def main():
    print("🔐 Secure Password Generator 🔐")
    try:
        length = int(input("Enter desired password length: "))
        password = generate_password(length)
        print(f"Your generated password is:\n👉 {password}")
    except ValueError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
