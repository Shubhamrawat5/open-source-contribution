def generateBins(n, m):
    bins = []
    for i in range(1, n + 1):
        t = bin(i)[:1:-1]
        t_l = len(t)
        m_0 = "0" * (m - t_l)
        bins.append(t + m_0)
    return bins


# n = hammingLength
# k = wordLength
# m = parityBits


def generator(dataword):
    k = len(dataword)
    m = 3
    while 2 ** m < (m + k + 1):
        m += 1
    n = m + k
    parityBits = [0, 1, 3, 7, 15, 31, 63]
    parityBits = parityBits[:m]
    print(f"\nNumber of parity bits {m}")
    hammingCode = [None] * n
    for i in parityBits:
        hammingCode[i] = "P"
    rev = dataword[::-1]
    j = 0
    for i in range(len(hammingCode)):
        if hammingCode[i] is None:
            hammingCode[i] = rev[j]
            j += 1
    j = 0
    print(f"The hamming code: {hammingCode[::-1]}")
    bins = generateBins(n, m)
    for i in range(n):
        if hammingCode[i] == "P":
            temp = 0
            for x in range(len(bins)):
                if bins[x][j] == "1" and (x not in parityBits):
                    temp += int(hammingCode[x])
            print(f"P{str(j+1)} = {str(temp%2)}")
            hammingCode[i] = str(temp % 2)
            j += 1
    print(f"The hamming code after substituting paritybits: {hammingCode[::-1]}")
    hammingCode = "".join(hammingCode[::-1])
    print(f"\nThe encoded code for {dataword} is: {hammingCode}\n")


def decoder(dataCode):
    n = len(dataCode)
    dataCode = dataCode[::-1]
    m = 3
    k = n - m
    while 2 ** m < (m + k + 1):
        m += 1
        k = n - m
    parityBits = [0, 1, 3, 7, 15, 31, 63]
    parityBits = parityBits[:m]
    bins = generateBins(n, m)
    syndromes = [None] * m
    for i in range(m):
        temp = 0
        for x in range(len(bins)):
            if bins[x][i] == "1":
                temp += int(dataCode[x])
        syndromes[i] = str(temp % 2)
    print(f"\nSyndromes: {syndromes[::-1]}\n")
    syndromes = list(reversed(syndromes))
    num = "".join(syndromes)
    dec = int(num, 2)
    decodedCode = []
    if dec != 0:
        change_idx = n - 2 - dec
        temp = dataCode[change_idx]
        ins = "1" if temp == "0" else "0"
        dataCode = dataCode[:change_idx] + ins + dataCode[change_idx + 1 :]
        print("The data was manipulated at index:", dec)
    for i in range(n):
        if i not in parityBits:
            decodedCode.append(dataCode[i])
    print(f'The decoded code is: {"".join(decodedCode[::-1])}\n')


encode = input("Enter the dataword: ")
generator(encode)

decode = input("Enter the received word: ")
decoder(decode)
