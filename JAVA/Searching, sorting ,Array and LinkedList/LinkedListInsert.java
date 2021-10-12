package com.company;

public class LinkedListInsert {
    LinkedListInsert.Node head;

    static class Node{
        int data;
        Node next;
        Node(int d){
            this.data=d;
            next=null;
        }
    }

    public void printList(){
        Node n = head;
        while (n!=null){
            System.out.print(n.data+" ");
            n=n.next;
        }
    }

//    insert at beginning
    public void push(int newData){
        Node newNode = new Node(newData);
        newNode.next=head;
        head=newNode;
    }

//    insert after the node
    public void insertAfter(Node prevNode, int newData){
        if (prevNode == null){
            System.out.println("Given previous node cannot be null");
            return;
        }

        Node newNode = new Node(newData);
        newNode.next=prevNode.next;
        prevNode.next = newNode;

    }

    public void append(int newData){
        Node newNode = new Node(newData);
        if (head==null){
            head = new Node(newData);
            return;
        }
        newNode.next=null;
        Node last = head;

        while (last.next!=null){
            last=last.next;
        }
        last.next = newNode;
        return;
    }


    public static void main(String[] args) {
        LinkedListInsert l = new LinkedListInsert();
        l.append(6);
        l.push(7);
        l.push(1);
        l.append(4);
        l.insertAfter(l.head.next,8);
        l.printList();

    }
}
