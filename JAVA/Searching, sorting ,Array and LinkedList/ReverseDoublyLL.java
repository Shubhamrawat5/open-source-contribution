package com.company;

public class ReverseDoublyLL {


        static Node head;

        static class Node {

            int data;
            Node next, prev;

            Node(int d)
            {
                data = d;
                next = prev = null;
            }
        }

        void reverse()
        {
            Node temp = null;
            Node current = head;

            while (current != null) {
                temp = current.prev;
                current.prev = current.next;
                current.next = temp;
                current = current.prev;
            }


            if (temp != null) {
                head = temp.prev;
            }
        }


        void push(int newdata)
        {
            Node newnode = new Node(newdata);

            newnode.prev = null;

            newnode.next = head;

            if (head != null) {
                head.prev = newnode;
            }

            head = newnode;
        }

        void printList(Node node)
        {
            while (node != null) {
                System.out.print(node.data + " ");
                node = node.next;
            }
        }

        public static void main(String[] args)
        {
            ReverseDoublyLL list = new ReverseDoublyLL();

            list.push(2);
            list.push(4);
            list.push(8);
            list.push(10);

            System.out.println("Original linked list ");
            list.printList(head);

            list.reverse();
            System.out.println("");
            System.out.println("The reversed Linked List is ");
            list.printList(head);
        }




}
