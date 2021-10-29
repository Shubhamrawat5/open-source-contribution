import Queue


class Node:
    def __init__(self, val, ops):
        self.val = val
        self.ops = ops


def min_operations(x, y):
    queue = Queue.Queue()
    queue.put(Node(x, 0))

    while queue:
        curr = queue.get()

        if curr.val == y:
            return curr.ops

        if curr.val * 2 == y or curr.val - 1 == y:
            return curr.ops + 1

        queue.put(Node(curr.val * 2, curr.ops + 1))
        queue.put(Node(curr.val - 1, curr.ops + 1))
    return -1


print(min_operations(2, 5))
