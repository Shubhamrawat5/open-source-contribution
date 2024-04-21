def mostActive(customers):
    # Write your code here
    rank=[]
    dict={}
    
    for i in customers:
        percent=0
        if i not in dict:
           count_t=customers.count(i)
           percent=(count_t/len(customers)*100)
           dict[i]=round(percent, 2)
    cur=0
    for i , j in dict.items():
        
        if j >= (5/100)*len(customers):
            rank.append(i)
            cur=j
    rank.sort()
    print(rank)
    print(dict)
           
           
        

if __name__ == '__main__':
    

    customers_count = int(input().strip())

    customers = []

    for _ in range(customers_count):
        customers_item = input()
        customers.append(customers_item)

    mostActive(customers)

   