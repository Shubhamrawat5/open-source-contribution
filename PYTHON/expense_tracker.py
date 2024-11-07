# Improvements :Add Error Handling and User Experience features. Updated code

class Expense:
    def __init__(self, description, amount):  # Initialize with description and amount
        self.description = description
        self.amount = amount

    def __str__(self):  # String representation of an expense
        return f"{self.description}: ${self.amount:.2f}"

class ExpenseTracker:
    def __init__(self):  # Initialize an empty expense list
        self.expenses = []

    def add_expense(self, description, amount):  # Add a new expense
        self.expenses.append(Expense(description, amount))
        print(f"Added: {description} - ${amount:.2f}")

    def view_expenses(self):  # View all recorded expenses
        if not self.expenses:
            print("No expenses recorded!")  # If no expenses exist
        else:
            for i, expense in enumerate(self.expenses, 1):  
                print(f"{i}. {expense}")
            print(f"Total: ${self.total_expenses():.2f}")  # Display total expenses

    def total_expenses(self):  # Calculate the total expenses
        return sum(expense.amount for expense in self.expenses)

    def delete_expense(self, expense_num):  # Delete an expense by number
        try:
            removed_expense = self.expenses.pop(expense_num - 1)  # Remove by index
            print(f"Deleted: {removed_expense.description}")
        except IndexError:  # Handle invalid expense number
            print("Invalid expense number!")

def display_menu():  # Display menu options
    print("\n1. Add Expense\n2. View Expenses\n3. Delete Expense\n4. Exit")

def main():  # Main function to run the tracker
    tracker = ExpenseTracker()  
    while True:
        display_menu()  
        choice = input("Choose an option (1-4): ")

        if choice == "1":
            description = input("Enter expense description: ")  
            try:
                amount = float(input("Enter amount: "))
                tracker.add_expense(description, amount)  
            except ValueError:
                print("Invalid amount. Please enter a numeric value.")
        elif choice == "2":
            tracker.view_expenses()  
        elif choice == "3":
            tracker.view_expenses()  
            try:
                expense_num = int(input("Expense number to delete: "))
                tracker.delete_expense(expense_num) 
                tracker.view_expenses()  # Show updated expenses after deletion
            except ValueError:
                print("Invalid input. Please enter a number.")
        elif choice == "4":
            print("Goodbye!")  # Exit program
            break
        else:
            print("Invalid choice, try again.")  # Handle invalid input

if __name__ == "__main__":
    main()  # Run the program
