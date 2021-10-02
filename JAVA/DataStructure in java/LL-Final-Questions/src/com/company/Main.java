package com.company;

public class Main {

    public static void main(String[] args) {
    LinkedList ll = new LinkedList();
    ll.createLL(1);
    ll.insertNode(5);
    ll.insertNode(2);
    ll.insertNode(2);
    ll.insertNode(8);
    ll.insertNode(7);
    ll.insertNode(5);

        ll.traverseLL();
    Questions q= new Questions();
    q.deleteDups(ll);
    ll.traverseLL();
        System.out.println(q.nthToLast(ll,3).value);

    }
}
