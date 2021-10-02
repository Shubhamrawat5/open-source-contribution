package com.company;

public class Main {

    public static void main(String[] args) {
    QueueLinkedList newQLL = new QueueLinkedList();

        System.out.println(newQLL.isEmpty());
        newQLL.enQueue(7);
        newQLL.enQueue(8);
        newQLL.enQueue(9);
        newQLL.enQueue(5);
        System.out.println(newQLL.isEmpty());
        System.out.println(newQLL.deQueue());
        System.out.println(newQLL.deQueue());
//      newQLL.deleteQueue();
//        System.out.println(newQLL.peek());


    }
}
