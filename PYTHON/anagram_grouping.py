from collections import defaultdict
import string


def group_anagrams(strings):
    groups = defaultdict(list)

    for s in strings:
        charset = {x: 1 for x in string.lowercase}
        for char in s:
            charset[char] += 1
        key = ''.join(map(str, charset.values()))
        groups[key].append(s)
    return groups.values()


def main():
    strings = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(group_anagrams(strings))


if __name__ == '__main__':
    main()
