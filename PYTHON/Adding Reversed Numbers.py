n = int(input())
ans = 0
number = 0
for i in range(n):
    a, b = map(int, input().split())
    A = int(str(a)[::-1])  # reverse
    B = int(str(b)[::-1])  # reverse
    ans = A + B
    number = int(str(ans)[::-1])  # reverse
    print(number) 
