from random import randint

t = ['rock','paper','scissors']
comp = t[randint(0,2)]
player = False

while player == False:
    player = input("Choose one from: rock, paper, scissors\n")
    if player == comp:
        print('Tie!')
    elif player == 'rock':
        if comp == 'paper':
            print('You LOSE! Paper covers Rock.')
        else:
            print('You WIN! Scissors cut Paper.')
    elif player == 'paper':
        if comp == 'rock':
            print('You WIN! Paper covers Rock.')
        else:
            print('You LOSE! Rock destroys Scissors.')
    elif player == 'scissors':
        if comp == 'paper':
            print('You WIN! Scissors cut Paper.')
        else:
            print('You LOSE! Rock destroys Scissors.')
    else:
        print('The spelling seems to be incorrect. Kindly check the spelling once!')

player = False
comp = t[randint(0,2)]
