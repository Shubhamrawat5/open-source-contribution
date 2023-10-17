def arrangeCoins(n):
    left, right = 0, n
    while left <= right:
        k = left + (right - left) // 2
        curr = k * (k + 1) // 2
        if curr == n:
            return k
        if curr > n:
            right = k - 1
        else:
            left = k + 1
    return right

n = int(input("Enter the number of coins: "))
result = arrangeCoins(n)
print("The number of full staircases that can be arranged with", n, "coins:", result)
