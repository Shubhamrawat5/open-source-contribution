package com.company;

public class OperationsOnCircularLL2 {
    static class Node {
        int data;
        Node next;
    };

    static Node push(Node head_ref, int data) {
        Node ptr1 = new Node();
        ptr1.data = data;
        ptr1.next = head_ref;

        if (head_ref != null) {
            Node temp = head_ref;
            while (temp.next != head_ref)
                temp = temp.next;
            temp.next = ptr1;
        }
        else
            ptr1.next = ptr1;

        head_ref = ptr1;
        return head_ref;
    }

    static void printList(Node head)
    {
        Node temp = head;
        if (head != null) {
            do {
                System.out.printf("%d ", temp.data);
                temp = temp.next;
            } while (temp != head);
        }

        System.out.printf("\n");
    }

    static Node deleteNode(Node head, int key)
    {
        if (head == null)
            return null;

        Node curr = head, prev = new Node();
        while (curr.data != key) {
            if (curr.next == head) {
                System.out.printf("\nGiven node is not found"
                        + " in the list!!!");
                break;
            }

            prev = curr;
            curr = curr.next;
        }

        if (curr == head && curr.next == head) {
            head = null;
            return head;
        }

        if (curr == head) {
            prev = head;
            while (prev.next != head)
                prev = prev.next;
            head = curr.next;
            prev.next = head;
        }

        else if (curr.next == head) {
            prev.next = head;
        }
        else {
            prev.next = curr.next;
        }
        return head;
    }

    public static void main(String args[]) {
        Node head = null;

        // Created linked list will be 2.5.7.8.10
        head = push(head, 2);
        head = push(head, 5);
        head = push(head, 7);
        head = push(head, 8);
        head = push(head, 10);

        System.out.printf("List Before Deletion: ");
        printList(head);

        head = deleteNode(head, 7);

        System.out.printf("List After Deletion: ");
        printList(head);
    }
}
