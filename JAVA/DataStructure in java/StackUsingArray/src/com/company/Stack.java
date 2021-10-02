package com.company;

public class Stack {
    int[] arr;
    int topOfStack;

    public Stack(int size){
        this.arr =new int[size];
        this.topOfStack=-1;
        System.out.println("the tack is created with size : "+ size);
    }

    public boolean isEmpty(){
        if (topOfStack==-1){
//            System.out.println("Stack is empty");
            return true;
        }
        else {
            return false;
        }
    }

    public boolean isFull(){
        if (topOfStack==arr.length-1){
//            System.out.println("The stack is full");
            return true;
        }else {
            return false;
        }
    }

//    push
    public void push(int value){
        if (isFull()){
            System.out.println("stack is full");
        }else {
            arr[topOfStack+1]=value;
            topOfStack++;
//            System.out.println("the value is successfully inserted");
        }
    }

    public int pop(){
        if (isEmpty()){
            System.out.println("Stack is empty!");
            return -1;
        }else {
            int topStack = arr[topOfStack];
            topOfStack--;
            return topStack;
        }
    }
//    peek
    public int peek(){
        if (isEmpty()){
            System.out.println("stack is empty");
            return -1;
        }else {
            return arr[topOfStack];
        }
    }

    //  Delete method
    public void deleteStack() {
        arr = null;
        System.out.println("The Stack is successfully deleted");
    }




}
