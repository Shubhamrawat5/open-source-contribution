package com.company;

public class Main {

    public static void main(String[] args) {
        CircularDoublyLinkedList cDLL = new CircularDoublyLinkedList();

        cDLL.insertNode(9,1);
        cDLL.insertNode(7,2);
        cDLL.insertNode(5,3);
        cDLL.insertNode(4,0);

        cDLL.traverseCDLL();

        cDLL.deleteNode(2);
        cDLL.traverseCDLL();
    }
}
