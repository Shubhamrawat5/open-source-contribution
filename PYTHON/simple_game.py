#Game CLI

import random


def get_map(num1,num2):
    result = []
    idx = 0
    try:
        for x in range(num1):
            for y in range(num2):
                result.insert(idx,(x,y))
                idx += 1
            idx += 1
    except:
        print("Value Must Number")

    return result,num1,num2


#manually define map
#CELLS =[(0,0), (0,1), (0,2), (0,3), (0,4),
#       (1,0), (1,1), (1,2), (1,3), (1,4),
#       (2,0), (2,1), (2,2), (2,3), (2,4),
#       (3,0), (3,1), (3,2), (3,3), (3,4)]

CELLS,valx,valy = get_map(10,20)
type(CELLS)



def get_location():
    #random player
    #random door
    #random monster
    start = random.choice(CELLS)
    door = random.choice(CELLS)
    monster = random.choice(CELLS)

    if start == door or start == monster or monster == door:
        return get_location()

    return start,door,monster



def get_move(player):
    moves = ["LEFT","RIGHT","UP","DOWN"]
    x, y = player
    
    if x == 0:
        moves.remove("UP")
    if x == valx-1:
        moves.remove("DOWN")
    if y == 0:
        moves.remove("LEFT")
    if y == valy-1:
        moves.remove("RIGHT")
        
    return moves

        
def player_move(player,move):

    x, y = player

    if move == "LEFT":
        y -= 1
    elif move == "RIGHT":
        y += 1
    elif move == "UP":
        x -= 1
    elif move == "DOWN":
        x += 1
        
    return x,y
    
def draw_map(player):

    for x in range(valy):
        if x == valy-1:
            print(' _')
            break
        else:
            print(' _',end='')
        
    tile = '|{}'
    rightidx = []
    count,val = 0,0
    for x in range(valx):
        if val == 0:
            val += count + valy-1
            rightidx.append(val)
        else:
            val += count + valy
            rightidx.append(val)

        #rightidx.append(val)

    for idx, cell in enumerate(CELLS): 
        if idx not in rightidx:
            if cell == player:
                print(tile.format('X'), end='')
            elif cell == door:
                print(tile.format('G'), end='')
            else:
                print(tile.format('_'), end='')
        else:
            if cell == player:
                print(tile.format('X|'))
            elif cell == door:
                print(tile.format('G|'))
            else:
                print(tile.format('_|'))
                
player,door,monster = get_location()
print("Welcome to the dungeon")

while True:
    moves = get_move(player)
    print("You are in room {}".format(player))
    draw_map(player)
    #print("Door in room {}".format(door))
    #print("Monster in room {}".format(monster))
    print("You can move to {}".format(moves))
    print("type QUIT to quit")

    move = input("> ")
    move = move.upper()

    if move == "QUIT":
        break

    if move in moves:
          player = player_move(player,move)
    else:
          print("Don't try to walk in wall")
          continue
    

    if player == monster:
        print("Ente kemakan monster gan ")
        break
    elif player == door:
        print("Bisa kabur hebat ente gan ")
        break
