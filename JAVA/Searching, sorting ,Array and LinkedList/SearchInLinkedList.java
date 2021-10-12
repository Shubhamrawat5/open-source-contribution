package com.company;

public class SearchInLinkedList {
    Node head;

    public static class Node{
        int data;
       Node next;
        Node(int d){
            this.data=d;
            next=null;
        }
    }

    public void printList(){
        Node n = head;
        while (n!=null){
            System.out.print(n.data+" ");
            n=n.next;
        }
    }

    //    insert at beginning
    public void push(int newData){
        Node newNode = new Node(newData);
        newNode.next=head;
        head=newNode;
    }

    //    insert after the node
    public void insertAfter(Node prevNode, int newData){
        if (prevNode == null){
            System.out.println("Given previous node cannot be null");
            return;
        }

        Node newNode = new Node(newData);
        newNode.next=prevNode.next;
        prevNode.next = newNode;

    }
    //  Insert at end
    public void append(int newData){
        Node newNode = new Node(newData);
        if (head==null){
            head = new Node(newData);
            return;
        }
        newNode.next=null;
        Node last = head;

        while (last.next!=null){
            last=last.next;
        }
        last.next = newNode;
        return;
    }

    public int SearchInLL(int element){
        Node n = head;
        int i=1;
        while (n!=null){
             if (n.data==element){
                 return i;
             }
             i++;
            n=n.next;
        }
        return -1;
    }

    public void deleteNode(int key){
        Node temp = head, prev = null;

        if (temp !=null && temp.data ==key){
            head = temp.next;
            return;
        }

        while (temp!=null && temp.data != key){
            prev=temp;
            temp=temp.next;
        }

        if (temp==null){
            return;
        }

        prev.next=temp.next;

    }


//      method 2nd ofr search
    public boolean search(Node head, int x)
    {
        if (head == null)
            return false;

        if (head.data == x)
            return true;

        return search(head.next, x);
    }

    public static void main(String[] args) {
        SearchInLinkedList l = new SearchInLinkedList();
        l.push(7);
        l.push(1);
        l.push(3);
        l.push(2);

        System.out.println();
        System.out.println(l.SearchInLL(3));
        System.out.println(l.search(l.head,2));
    }
}
