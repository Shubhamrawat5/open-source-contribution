package com.company;

public class Main {

    public static void main(String[] args) {

        SinglyLinkedList SLL = new SinglyLinkedList();

        SLL.createSinglyLinkedList(5);
        SLL.insertInLinkedList(4,1);
        SLL.insertInLinkedList(7,7);
        SLL.insertInLinkedList(6,1);
//        SLL.searchNode(7);
        SLL.traverseLinkedList();

        SLL.deleteNode(1);
        SLL.traverseLinkedList();
    }
}
