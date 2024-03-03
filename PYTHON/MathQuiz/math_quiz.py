#This program will demonstrate simple math quizzes that allows the user
#to enter their answer, show if correct, else incorrect.
import random
num1 = random.randint(1,100)
num2 = random.randint(1,100)
total = num1 + num2
print(f'\n  {num1}\n+ {num2}\n ----------')

user_answer = int(input('Enter your answer: '))

def valid(user_answer, total):
    if user_answer == total:
        print('\nYou are correct! :)\n')
    else: 
        print(f'You are incorrect.\nThe correct answer is {total}.\n')

valid(user_answer, total)
