package com.company;
import java.util.HashSet;

public class Questions {
        public void deleteDups(LinkedList ll){
            HashSet<Integer> hs = new HashSet();
        Node current  = ll.head;
        Node prev = null;
        while (current!=null){
            int curval = current.value;
            if (hs.contains(curval)){
                prev.next=current.next;
                ll.size--;
            }else {
                hs.add(curval);
                prev=current;
            }
            current=current.next;
        }

    }

    Node nthToLast(LinkedList ll, int n){
        Node ptr1 = ll.head;
        Node ptr2 = ll.head;

        for (int i = 0; i < n; i++) {
            if (ptr2==null) return null;
            ptr2=ptr2.next;
        }

        while (ptr2!=null){
            ptr1=ptr1.next;
            ptr2=ptr2.next;
        }
        return ptr1;
    }


//    q4
// Question 4 - Sum Lists
LinkedList sumLists(LinkedList llA, LinkedList llB) {
    Node n1 = llA.head;
    Node n2 = llB.head;
    int carry = 0;
    LinkedList resultLL = new LinkedList();
    while (n1 != null || n2 != null) {
        int result = carry;
        if (n1 != null) {
            result += n1.value;
            n1 = n1.next;
        }
        if (n2 != null) {
            result += n2.value;
            n2 = n2.next;
        }
        resultLL.insertNode(result%10);
        carry = result / 10;
    }
    return resultLL;
}

    // Question 5 - Intersection
    // getKthNode
    Node getKthNode(Node head, int k) {
        Node current = head;
        while (k>0 && current != null) {
            current = current.next;
            k--;
        }
        return current;
    }

    // Intersection Method
    Node findIntersection(LinkedList list1, LinkedList list2) {
        if (list1.head == null || list2.head == null) return null;
        if (list1.tail != list2.tail) {
            return null;
        }
        Node shorter = new Node();
        Node longer = new Node();
        if (list1.size > list2.size) {
            longer = list1.head;
            shorter = list2.head;
        } else {
            longer = list2.head;
            shorter = list1.head;
        }

        longer = getKthNode(longer, Math.abs(list1.size-list2.size));
        while (shorter != longer) {
            shorter = shorter.next;
            longer = longer.next;
        }
        return longer;

    }

    // Add same node
    void addSameNode(LinkedList llA, LinkedList llB, int nodeValue) {
        Node newNode = new Node();
        newNode.value = nodeValue;
        llA.tail.next = newNode;
        llA.tail = newNode;
        llB.tail.next = newNode;
        llB.tail = newNode;









    }