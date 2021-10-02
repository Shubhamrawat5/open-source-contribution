package com.company;

public class QueueLinkedList {
    LinkedList list;

    public QueueLinkedList() {
        list= new LinkedList();
        System.out.println("Queue is created");
    }

    public boolean isEmpty(){
        return (list.head==null);
    }

    public void enQueue(int value){
        list.insertInLinkedList(value,list.size);
//        System.out.println("inserted successfully");
    }

    public int deQueue(){
        int value=-1;
        if (isEmpty()){
            System.out.println("queue is empty");
            return value;
        }else {
            value=list.head.value;
            list.deletionOfNode(0);
        }
        return value;
    }

    public int peek(){
        if (isEmpty()){
            System.out.println("queue is empty");
            return -1;
        }else {
            return list.head.value;
        }

    }

    public void deleteQueue(){
        list.head=null;
        list.tail=null;
        System.out.println("Queue deleted");
    }





}
