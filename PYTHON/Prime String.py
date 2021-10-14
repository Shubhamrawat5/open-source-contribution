''' Read input from STDIN. Print your output to STDOUT '''
    #Use input() to read input from STDIN and use print to write your output to STDOUT

def main():
    T = int(input())
    for i in range(T):
        k = input()
        Esum = 0
        Osum = 0
        AD = 0
        counter = 0
        for j in k:
            print(ord(j))
            if counter%2 == 0 :
                Esum += ord(j)
            else:
                Osum += ord(j)  

            counter +=1

        if ((Esum - Osum) < 0 ):
            AD = Osum - Esum
        else:
            AD = Esum - Osum

        if ( AD%3 == 0 or AD%5 == 0 or AD%7 == 0 ):
            print("Prime String")

        else:
            print("Casual String")

main()

