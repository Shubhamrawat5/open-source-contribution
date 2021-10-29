from collections import defaultdict


def find_transformation(startWord, endWord, wordList):
    d = defaultdict(list)
    for w in wordList:
        for i in range(len(w)):
            d[w[:i] + '*' + w[i + 1:]].append(w)

    queue, visited = [(startWord, 1)], set()
    while queue:
        word, length = queue.pop()
        if word == endWord:
            return length
        visited.add(word)
        for i in range(len(word)):
            for w in d[word[:i] + '*' + word[i + 1:]]:
                if w not in visited:
                    queue.append((w, length + 1))
    return -1


def main():
    startWord = 'hit'
    endWord = 'cog'
    wordList = ['hot', 'dot', 'dog', 'lot', 'log', 'cog']
    print(find_transformation(startWord, endWord, wordList))


if __name__ == '__main__':
    main()
