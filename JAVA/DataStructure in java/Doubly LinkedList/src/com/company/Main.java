package com.company;

public class Main {

    public static void main(String[] args) {
    DoublyLinkedList dll = new DoublyLinkedList();

    dll.createDLL(5);
//        System.out.println(dll.head.value);

        dll.insertDLL(8,6);
        dll.insertDLL(4,0);
        dll.insertDLL(7,1);

        dll.show();
        dll.showBackward();

//        dll.searchNode(5);

        dll.deleteNodeDLL(0);
        dll.show();

//        dll.deleteEntireDLL();
//        dll.showBackward();

    }
}
