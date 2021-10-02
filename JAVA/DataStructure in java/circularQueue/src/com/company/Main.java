package com.company;

public class Main {

    public static void main(String[] args) {
        CircularQueue newCQ =new CircularQueue(3);


//        System.out.println(newCQ.isEmpty());
//        System.out.println(newCQ.isFull());
        newCQ.enQueue(4);
        newCQ.enQueue(4);
        newCQ.enQueue(4);


        newCQ.deQueue();
//        System.out.println(newCQ.deQueue());
        System.out.println(newCQ.peek());
    }
}
