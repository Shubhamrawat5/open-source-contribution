package hacktoberfest;

public class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) 
	{ 
		this.val = val; 
	}
	ListNode(int val, ListNode next) 
	{ 
		this.val = val; this.next = next;
	}
}

class Main {
    public ListNode middleNode(ListNode head) {
        //tortoise hare algorithm
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
}
