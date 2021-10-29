class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

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

    def add(self, data):
        if self.root:
            self._add(self.root, data)
        else:
            self.root = Node(data)

    def same_tree(self, t1, t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        if t1.data != t2.data:
            return False
        return self.same_tree(t1.left, t2.left) and self.same_tree(t1.right, t2.right)


def main():
    B1 = BST()
    nodes = [8, 3, 10, 1, 6, 4, 7, 13, 14]
    for n in nodes:
        B1.add(n)

    B2 = BST()
    nodes = [8, 3, 10, 1, 6, 4, 7, 13, 14]
    for n in nodes:
        B2.add(n)

    print(B1.same_tree(B1.root, B2.root))


if __name__ == '__main__':
    main()
