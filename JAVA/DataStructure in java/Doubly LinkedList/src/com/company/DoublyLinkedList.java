package com.company;

public class DoublyLinkedList {
    DoublyNode head;
    DoublyNode tail;
    int size;
    public DoublyNode createDLL(int nodeValue){
        head = new DoublyNode();
        DoublyNode newNode = new DoublyNode();
        newNode.value = nodeValue;
        newNode.next=null;
        newNode.prev=null;

        head = newNode;
        tail = newNode;
        size=1;

        return head;
    }

//    insertion
    public void insertDLL(int nodeValue, int location){
        DoublyNode newNode = new DoublyNode();
        newNode.value=nodeValue;

        if (head==null){
            createDLL(nodeValue);
            return;
        }else if(location==0){
            newNode.next=head;
            newNode.prev=null;
            head.prev=newNode;
            head=newNode;
        }else if (location>=size){
            newNode.next=null;
            tail.next=newNode;
            newNode.prev=tail;
            tail = newNode;
        }else {
            DoublyNode tempNode = head;
            int index=0;
            while(index<location-1){
                tempNode=tempNode.next;
                index++;
            }
            //reached to prev node location

            newNode.prev=tempNode;
            newNode.next=tempNode.next;

            tempNode.next=newNode;
            newNode.next.prev=newNode;
        }
        size++;
    }

    public void show(){
       if (head!=null) {
           DoublyNode node = head;
           System.out.println("Forward traversal");
           for (int i = 0; i < size; i++) {
               System.out.print(node.value + " ");
               if (node.next != null) System.out.print(" -> ");
               node = node.next;
           }
        }else {
           System.out.println("DLL not exist");
       }
        System.out.println("\n");
    }
    public void showBackward(){
       if (head!=null) {
           DoublyNode node = tail;
           System.out.println("Backward traversal");
           for (int i = 0; i < size; i++) {
               System.out.print(node.value + " ");
               if (node.prev != null) System.out.print(" <- ");
               node = node.prev;
           }
        }else {
           System.out.println("DLL not exist");
       }
        System.out.println("\n");
    }

    // Search Node
    public boolean searchNode(int nodeValue) {
        if (head != null) {
            DoublyNode tempNode = head;
            for (int i = 0; i < size; i++) {
                if (tempNode.value == nodeValue) {
                    System.out.print("The Node is found at location: " +i);
                    return true;
                }
                tempNode = tempNode.next;
            }
        }
        System.out.print("Node not found!");
        return false;
    }

    // Deletion Method

    public void deleteNodeDLL(int location){
        if (head==null){
            System.out.println("DLL not exist!");
        return;
        }
        else if (location==0){
            if (size==1){
                head=null;
                tail=null;
                size--;
                return;
            }else {
                head=head.next;
                head.prev=null;
                size--;
            }
        }else if(location>=size){
            DoublyNode tempNode = tail.prev;
            if (size==1){
                head=null;
                tail=null;
                size--;
                return;
            }else {
                tempNode.next=null;
                tail=tempNode;
                size--;
            }
        }else {
            DoublyNode tempNode  = head;
            for (int i = 0; i < location - 1; i++) {
                tempNode=tempNode.next;
            }
            tempNode.next=tempNode.next.next;
            tempNode.next.prev =tempNode;
            size--;
        }
    }

    public void deleteEntireDLL(){
        DoublyNode tempNde =head;
        for (int i = 0; i < size; i++) {
            tempNde.prev=null;
            tempNde=tempNde.next;
        }
        head=tail=null;
        System.out.println("DLL has been deleted");
    }




}
