class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

class Heap:

    def __init__(self, data=None):
        self.list=[]


    def createHeap(self,data):
        self.list=data[:]
        for i in range(len(data)//2,-1,-1):
            self.heapify(i)
        return self.list

    def heapify(self,pos=0):
          if len(self.list)==0:
              return "Empty"
          while ( pos<=len(self.list)//2 -1) and (self.list[pos]>self.list[2*pos+1] or self.list[pos]>self.list[2*pos+2]):
                  if self.list[2*pos +1]==min(self.list[pos],self.list[2*pos+1],self.list[2*pos+2]):
                        self.list[pos],self.list[2*pos+1]=self.list[2*pos+1],self.list[pos]
                  else:
                      self.list[pos], self.list[2 * pos + 2] = self.list[2 * pos + 2], self.list[pos]
                  pos+=1
          return "Heapified"

    def insert(self,data):
        return False




from queue import Queue
def createTree(arr):
    if len(arr)==0 or arr[0]==-1:
        return None
    q= Queue()
    q.put(Node(arr[0]))
    i=1

    while q.qsize()!=0:
        root=q.get()
        if i==1:
            r=root
        if arr[i]!=-1:
            left=Node(arr[i])
            q.put(left)
            root.left = left
        i += 1

        if arr[i]!=-1:
            right=Node(arr[i])
            q.put(right)
            root.right = right
        i += 1

    return r


def prinTree(root):
    if root==None:
        return
    print(root.data)

    prinTree(root.left)
    prinTree(root.right)

def createBst(arr):
     n=len(arr)
     if  n==0:
         return None
     root=Node(arr[n//2])
     left=createBst(arr[:(n//2)])
     right=createBst(arr[(n//2)+1:])

     root.left=left
     root.right=right
     return root

def reverseTree(root):
    if root.left==None:
        return root
    temp=root.left
    root.left=root.right
    root.right=temp
    reverseTree(root.left)
    reverseTree(root.right)
    return root

a=list(map(int,input().split()))
root=createTree(a)
prinTree(root)
root2=reverseTree(root)
print("zzzzzzzzzzzzzzzzz")
prinTree(root2)
#root=createBst(a)

#heap=Heap()
#heapData=heap.createHeap([1,4,3,6,33,23])
#print(heapData)


