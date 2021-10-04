# This program shows heap sort
def heap(arr, n, i):
    #Declaring largest as parent, left and right from the array
    largest = i  
    left = 2 * i + 1     
    right = 2 * i + 2     
    
    #Looking if left side of child exists and if it is greater than root
    if left < n and arr[largest] < arr[left]:
        largest = left
        
    #Looking if right side of child exists and if it is greater than root
    if right < n and arr[largest] < arr[right]:
        largest = right
        
    #Changing the root if it is possibility
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swaping the places
 
        # Heaping the root.
        heap(arr, n, largest)
        
def Sort(arr):
    n = len(array)
    
    for i in range(n//2 -1, -1,-1):
        heap(array,n,i)
    
    for i in range(n-1,0 , -1):
        t = array[i]
        array[i] = array[0]
        array[0] = t
        heap(arr,i,0)

array = list(map(int, input().split()))#input in single line and spacing between characters
Sort(array)
t = input("Do you want this in ascending or decending order(A/D):")#ascending or decending
n = len(array)
if t == "A":
    for i in range(n):
        print("%d" % array[i])
else:
    array.reverse()
    for i in range(n):
        print("%d" % array[i])