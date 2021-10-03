# This program shows bubble sort
array = list(map(int, input().split()))#input in single line and spacing between characters

t = input("Do you want this in ascending or decending order(A/D):")#ascending or decending

#iterating through loops
for i in range(len(array)):
    for j in range(len(array)-1):
        #checking the condition
        if array[j]<array[j+1]:
            #swapping positions using a third variable tap
            tap = array[j]
            array[j] = array[j+1]
            array[j+1] = tap

if t=='D':
    print(*array)
else:
    array.reverse()
    print(*array)