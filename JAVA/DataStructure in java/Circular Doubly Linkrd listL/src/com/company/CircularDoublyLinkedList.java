package com.company;

public class CircularDoublyLinkedList {
    public DoublyNode head;
    public DoublyNode tail;
    public int size;

//    create CDLL
    public DoublyNode createCDLL(int nodeValue){
        head = new DoublyNode();
        DoublyNode newNode = new DoublyNode();
        newNode.value = nodeValue;
        head =newNode;
        tail= newNode;
        newNode.next=newNode;
        newNode.prev=newNode;
        size=1;
        return head;
    }

//    insertion into CDLL

    public void insertNode(int nodeValue, int location){
        DoublyNode newNode = new DoublyNode();
        newNode.value = nodeValue;

        if (head==null){
            createCDLL(nodeValue);
            return;
        }

        else if (location==0){
            newNode.next=head;
            newNode.prev= tail;
            head.prev= newNode;
            tail.next= newNode;
            head=newNode;
        }

        else if (location>=size){
            newNode.prev=tail;
            newNode.next=head;

            head.prev = newNode;
            tail.next=newNode;
            tail=newNode;
        }else {
            DoublyNode tempNode = head;
            int index = 0;
            while (index < location -1) {
                tempNode = tempNode.next;
                index++;
            }
            newNode.prev = tempNode;
            newNode.next = tempNode.next;
            tempNode.next = newNode;
            newNode.next.prev = newNode;
        }
        size++;
    }

    public void traverseCDLL(){
        if (head!=null){
            DoublyNode tempNode = head;
            for (int i = 0; i < size; i++) {
                System.out.print(tempNode.value+ " ");
                if (i!=size-1) {
                    System.out.print(" -> ");
                }
                tempNode= tempNode.next;
            }
        }else {
            System.out.println("CDLL does not exist!");
        }
        System.out.println();
    }

    // Reverse Traversal
    void reverseTraversalCDLL() {
        if (head != null) {
            DoublyNode tempNode = tail;
            for (int i=0; i<size; i++) {
                System.out.print(tempNode.value);
                if (i != size-1) {
                    System.out.print(" <- ");
                }
                tempNode = tempNode.prev;
            }

        } else {
            System.out.println("The CDLL does not exist!");
        }
    }

// Search for a Node



 // Search for a Node
    boolean searchNode(int nodeValue) {
        if (head != null) {
            DoublyNode tempNode = head;
            for (int i = 0; i < size; i++) {
                if (tempNode.value == nodeValue) {
                    System.out.println("The node is found at location: "+i);
                    return true;
                }
                tempNode = tempNode.next;
            }
        }
        System.out.println("Node not found! ");
        return false;
    }
//    delete node
    public void deleteNode(int location) {
        if (head == null) {
            System.out.println("CDLL does not exist");
        }

        else if(location==0){
            if (size == 1) {
                head.prev = null;
                head.next = null;
                head = tail = null;
                size--;
                return;
            } else {
                head = head.next;
                head.prev = tail;
                tail.next = head;
                size--;
            }
        }else if (location>=size){
            if (size == 1) {
                head.prev = null;
                head.next = null;
                head = tail = null;
                size--;
                return;
            } else{
                tail = tail.prev;
                tail.next=head;
                head.prev=tail;
                size--;
            }
        }else {
            DoublyNode tempNode = head;
            for (int i = 0; i < location - 1; i++) {
                tempNode=tempNode.next;
            }
            tempNode.next=tempNode.next.next;
            tempNode.next.prev=tempNode;
            size--;
        }
    }

    // Delete Entire CDLL
    public void deleteCDLL() {
        DoublyNode tempNode = head;
        for (int i=0; i<size; i++) {
            tempNode.prev = null;
            tempNode = tempNode.next;
        }
        head = null;
        tail = null;
        System.out.println("The CDLL has been deleted!");
    }
}