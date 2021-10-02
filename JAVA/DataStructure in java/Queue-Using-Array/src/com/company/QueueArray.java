package com.company;

public class QueueArray {
    int[] arr;
    int topOfQueue;
    int beginningOfQueue;

    public QueueArray(int size){
        this.arr = new int[size];
        this.topOfQueue =-1;
        this.beginningOfQueue =-1;
        System.out.println("queue created of size "+ size);
    }

    public boolean isFull(){
        return ( topOfQueue==arr.length-1 );
    }
    public boolean isEmpty(){
        return ( beginningOfQueue== -1 || beginningOfQueue==arr.length );
    }
//    Enqueue
    public void enQueue(int value){
        if(isFull()){
            System.out.println("queue Full");
        }else if(isEmpty()){
            beginningOfQueue =0;
            topOfQueue++;
            arr[topOfQueue] =value;
            System.out.println("successfully inserted at beginning");
        }else {
            topOfQueue++;
            arr[topOfQueue] =value;
            System.out.println("successfully inserted at top");
        }
    }

//    dequeue
        public int deQueue(){
        if (isEmpty()){
            System.out.println("queue is empty");
            return -1;
        }else {
            int result =arr[beginningOfQueue];
            beginningOfQueue++;
            if (beginningOfQueue>topOfQueue){
                beginningOfQueue=topOfQueue=-1;
            }
            return result;
        }
        }

//        peek
    public int peek(){
        if (!isEmpty()){
            return arr[beginningOfQueue];
        }else {
            return -1;
        }
    }

//    delete queue
    public void deleteQueue(){
        arr=null;
        System.out.println("Queue deleted successfully");
    }
















}
