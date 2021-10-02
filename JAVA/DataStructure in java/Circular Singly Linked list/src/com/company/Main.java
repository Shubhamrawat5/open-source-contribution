package com.company;

public class Main {

    public static void main(String[] args) {

    CircularSinglyLinkedList csLL = new CircularSinglyLinkedList();

    csLL.createCSSL(5);
//        System.out.println(csLL.head.next.value);
    csLL.insertCSSL(4,0);
    csLL.insertCSSL(2,1);
    csLL.insertCSSL(8,4);
        csLL.traversalCSLL();

        csLL.searchNode(5);
    }


}
