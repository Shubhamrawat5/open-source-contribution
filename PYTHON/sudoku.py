board = [[9,0,8,0,0,0,2,0,3],
    [0,4,0,0,9,0,0,6,0],
    [7,0,0,8,0,1,0,0,4],
    [6,0,0,4,0,9,0,0,0],
    [8,0,0,5,0,6,0,0,1],
    [0,0,0,3,0,2,0,0,0],
    [3,0,0,2,0,8,0,0,9],
    [0,8,0,0,6,0,0,4,0],
    [1,0,2,0,0,0,5,0,6]]



def print_board(bo):
    for i in range(9):
        if i % 3 == 0 and i != 0:
            print('- - - - - - - - - - - -')
        for j in range(9):
            if j % 3 == 0 and j != 0:
                print(' | ',end='')
            print(bo[i][j],end = ' ')
        print()



def find_empty(bo):
    for i in range(9):
        for j in range(9):
            if bo[i][j] == 0:
                return(i,j)
    else:
        return (None)



def valid(bo,num,pos):
    #row
    for j in range(9):
        if bo[pos[0]][j] == num and j != pos[1]:
            return (False)

    #column
    for i in range(9):
        if bo[i][pos[1]] == num and i!=pos[0] :
            return (False)

    #subgrid
    x_sub = int(pos[0]/3)
    y_sub = int(pos[1]/3)
    for i in range(x_sub * 3 , (x_sub * 3) + 3):
        for j in range(y_sub * 3 , (y_sub*3) + 3):
            if bo[i][j] == num and (i,j)!=pos:
                return(False)

    return (True)



def solve(bo):
    find = find_empty(bo)
    if not find :
        return (True)
    else :
        x,y = find

    for i in range(1,10):
        if valid(bo,i,(x,y)):
            bo[x][y] = i

            if solve(bo):
                return (True)

            bo[x][y] = 0

    return(False)



print_board(board)
solve(board)
print('\nSolution :\n')
print_board(board)
