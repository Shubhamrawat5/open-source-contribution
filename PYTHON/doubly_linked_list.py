class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self):
        self.head = None

    def create_list(self, arr):
        start = self.head
        n = len(arr)

        temp = start
        i = 0

        while i < n:
            new_node = Node(arr[i])
            if i == 0:
                start = new_node
                temp = start
            else:
                # Temp always point to last element
                temp.next = new_node
                new_node.prev = temp
                temp = temp.next
            i += 1

        self.head = start
        return start

    def print_list(self):
        temp = self.head
        linked_list = ''

        while temp:
            linked_list += str(temp.data) + " -> "
            temp = temp.next

        print(linked_list)

    def count_list(self) -> int:
        temp = self.head
        count = 0

        while temp is not None:
            temp = temp.next
            count += 1

        return count

    # Consider index starts at 1
    def insert_at_location(self, value, index):
        temp = self.head

        count = self.count_list()

        if count + 1 < index:
            return temp

        new_node = Node(value)

        # For head case
        if index == 1:
            new_node.next = temp
            temp.prev = new_node
            self.head = new_node
            return self.head

        # For tail case
        if index == count + 1:
            while temp.next is not None:
                temp = temp.next

            temp.next = new_node
            new_node.prev = temp

            return self.head

        i = 1

        # Temp is initially head
        while i < index - 1:
            # Temp is head.next
            temp = temp.next
            i += 1

        node_at_target = temp.next
        new_node.next = node_at_target
        node_at_target.prev = new_node

        temp.next = new_node
        new_node.prev = temp

        return self.head

    def delete_at_position(self, index):
        temp = self.head
        count = self.count_list()

        if count < index:
            return temp

        if index == 1:
            temp = temp.next
            self.head = temp
            temp.prev = None

            return self.head

        # Stop before the end of the list
        if count == index:
            while temp.next is not None and temp.next.next is not None:
                temp = temp.next
            last_node = temp.next
            last_node.prev = None
            temp.next = None
            return self.head

        i = 1

        while i < index - 1:
            temp = temp.next
            i += 1

        prev_node = temp
        node_at_target = temp.next
        next_node = temp.next.next

        prev_node.next = next_node
        next_node.prev = node_at_target

        node_at_target.next = None
        node_at_target.prev = None


arr = [1, 2, 3, 4, 5]

llist = LinkedList()
llist.create_list(arr)
llist.print_list()

# Nodes: 1 <-> 2 <-> 3 <-> 4 <-> 5
# Insert 9 at index 5 (index starts at 1)
# Nodes: 1 <-> 2 <-> 3 <-> 4 <-> 9 <-> 5
llist.insert_at_location(9, 5)
llist.print_list()

# Nodes: 1 <-> 2 <-> 3 <-> 4 <-> 9 <-> 5
# Delete node at index 5 (index starts at 1)
# Nodes: 1 <-> 2 <-> 3 <-> 4 <-> 5
llist.delete_at_position(5)
llist.print_list()
