package com.company;

public class CircularQueue {
    int[] arr;
    int topOfQueue;
    int beginningOfQueue;
    int size;

    public CircularQueue(int size){
        this.arr=new int[size];
        this.size=size;
        this.topOfQueue=-1;
        this.beginningOfQueue=-1;
        System.out.println("Queue created of size : "+ size);
    }

    public boolean isEmpty(){
        return (topOfQueue==-1 && beginningOfQueue==-1);
    }

    public boolean isFull(){
        return  (topOfQueue+1 == beginningOfQueue|| beginningOfQueue==0 && topOfQueue+1==size);
    }

    public void enQueue(int value){
        if (isFull()){
            System.out.println("Queue is full");
        }else if (isEmpty()){
            beginningOfQueue=0;
            topOfQueue++;
            arr[topOfQueue]=value;
            System.out.println("value inserted successfully");
        }else {
            if (topOfQueue+1==size){
                topOfQueue=0;
            }else {
                topOfQueue++;
            }
            arr[topOfQueue]=value;
            System.out.println("inserted successfully");
        }
    }

    public int deQueue(){
        if (isEmpty()){
            System.out.println("queue is empty");
            return -1;
        }else {
            int result = arr[beginningOfQueue];
            arr[beginningOfQueue]=0;
            if (beginningOfQueue==topOfQueue){
                beginningOfQueue=topOfQueue=-1;
            }else if (beginningOfQueue+1 ==size){
                beginningOfQueue=0;
            }else {
                beginningOfQueue++;
            }
            return result;
        }
    }

//    peek

    public int peek(){
        if (isEmpty()){
            System.out.println("queue is empty");
            return -1;
        }else {
            return arr[beginningOfQueue];

        }
    }

    public void deleteQueue(){
        arr=null;
        System.out.println("queue successfully deleted");
    }










}
