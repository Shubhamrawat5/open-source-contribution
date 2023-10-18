def getMaxRepetitions(s1, n1, s2, n2):
    len1, len2 = len(s1), len(s2)
    dp = [0] * (len2 + 1)
    repeatCount = [0] * (len2 + 1)
    j, count = 0

    for k in range(1, n1 + 1):
        for i in range(len1):
            if s1[i] == s2[j]:
                j += 1
                if j == len2:
                    j = 0
                    count += 1

        dp[k] = count
        repeatCount[k] = j

        for start in range(1, k):
            if repeatCount[start] == j:
                prefixCount = dp[start]
                repeatCountInterval = k - start
                prefixRepeats = (n1 - start) // repeatCountInterval
                suffixCount = dp[start + (n1 - start) % repeatCountInterval]
                return prefixCount + prefixRepeats * (dp[k] - prefixCount) + suffixCount

    return dp[n1]

s1 = input("Enter string s1: ")
n1 = int(input("Enter n1: "))
s2 = input("Enter string s2: ")
n2 = int(input("Enter n2: ")

result = getMaxRepetitions(s1, n1, s2, n2)
print("Maximum number of repetitions:", result)
