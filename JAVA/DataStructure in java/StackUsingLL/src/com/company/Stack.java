package com.company;

public class Stack {
    LinkedList linkedList;

    public Stack(){
        linkedList= new LinkedList();
    }

    public void push(int value){
     linkedList.insertInLinkedList(value,0);
        System.out.println("inserted "+value+" in stack");
    }

    public boolean isEmpty(){
        if (linkedList.head==null){
            return true;
        }else return false;
    }
    public int pop(){
        int result = -1;

        if (isEmpty()){
            System.out.println("stack empty");
        }else {
            result = linkedList.head.value;
            linkedList.deletionOfNode(0);
        }

        return result;
    }

        public int peek(){
            int result = -1;

            if (isEmpty()) {
                System.out.println("stack empty");
            }else {
                result = linkedList.head.value;
            }
            return result;
        }

//        delete method
        public void deleteStack(){
        linkedList.head=null;
            System.out.println("stack deleted");
        }





}
