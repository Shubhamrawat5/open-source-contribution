package com.company;

import java.util.LinkedList;

public class LinkedListCode {
    public Node head;

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

    public static void main(String[] args) {
        LinkedListCode l = new LinkedListCode();
        l.head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);

        l.head.next = second;
        second.next = third;

        l.printList();


    }


}