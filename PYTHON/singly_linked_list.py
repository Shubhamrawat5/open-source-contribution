class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def print_list(self):
        temp = self.head
        linked_list = ''

        while temp:
            linked_list += str(temp.data) + " -> "
            temp = temp.next
        print(linked_list)

    # lists start at 0
    def insert_node(self, val, pos):
        target = Node(val)

        # specific case for replacing head
        if pos == 0:
            target.next = self.head
            self.head = target
            return

        def get_prev(position):
            temp = self.head
            count = 1

            while count < position:
                temp = temp.next
                count += 1

            return temp

        # Getting previous node
        prev = get_prev(pos)

        if prev.next:
            # Temp variable for upcoming node
            next_node = prev.next

            # Set previous next to our target node
            prev.next = target

            # Set next node of target node from temp variable
            target.next = next_node

    def delete_node(self, key):
        temp = self.head

        if temp is None:
            return

        if temp.data == key:
            self.head = temp.next
            temp = None
            return

        while temp.next.data != key:
            temp = temp.next

        # Getting target node
        target_node = temp.next

        # Set previous node's next to target's next
        temp.next = target_node.next

        # Remove target node's pointer
        target_node.next = None


# Nodes: 4 -> 5 -> 7 -> 2

link = LinkedList()
link.head = Node(4)

first_node = Node(5)
second_node = Node(7)
third_node = Node(2)

link.head.next = first_node
first_node.next = second_node
second_node.next = third_node

link.print_list()

# Nodes: 4 -> 5 -> 7 -> 2
# Insert 3 at index 2
# Nodes: 4 -> 5 -> 3 -> 7 -> 2

link.insert_node(3, 2)
link.print_list()

# Nodes: 4 -> 5 -> 3 -> 7 -> 2
# Delete 3
# Nodes: 4 -> 5 -> 7 -> 2

link.delete_node(3)
link.print_list()
