# Write an algorithm to find the path with the maximum sum
from collections import deque


class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


class BST:
    def __init__(self):
        self.root = None

    def add(self, data):
        if not self.root:
            self.root = Node(data)
        else:
            self._add(self.root, data)

    def _add(self, node, data):
        if data <= node.data:
            if node.left:
                self._add(node.left, data)
            else:
                node.left = Node(data)
        else:
            if node.right:
                self._add(node.right, data)
            else:
                node.right = Node(data)

    def range_sum(self, root, L, R):
        queue = deque([root])
        total = 0

        while queue:
            node = queue.popleft()
            if node:
                if L <= node.data <= R:
                    total += node.data
                if L < node.data:
                    queue.append(node.left)
                if node.data < R:
                    queue.append(node.right)
        return total

    def range_sum_rec(self, root, L, R):
        if not root:
            return 0
        if root.data < L:
            return self.range_sum_rec(root.right, L, R)
        if root.data > R:
            return self.range_sum_rec(root.left, L, R)
        res = 0
        res += root.data
        res += self.range_sum_rec(root.left, L, R)
        res += self.range_sum_rec(root.right, L, R)
        return res


def main():
    B = BST()
    nodes = [8, 3, 10, 1, 6, 4, 7, 14, 13]
    for n in nodes:
        B.add(n)

    print(B.range_sum(B.root, 4, 10))
    print(B.range_sum_rec(B.root, 4, 10))


if __name__ == '__main__':
    main()
