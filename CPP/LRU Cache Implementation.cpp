/* LRU Cache Implementation

How to implement LRU caching scheme? What data structures should be used? 
We are given total possible page numbers that can be referred. We are also given cache (or memory) size (Number of page frames that cache can hold at a time). The LRU caching scheme is to remove the least recently used frame when the cache is full and a new page is referenced which is not there in cache. 
We use two data structures to implement an LRU Cache.  

Queue which is implemented using a doubly linked list. The maximum size of the queue will be equal to the total number of frames available (cache size). The most recently used pages will be near front end and least recently pages will be near the rear end. 
A Hash with page number as key and address of the corresponding queue node as value.
When a page is referenced, the required page may be in the memory. If it is in the memory, we need to detach the node of the list and bring it to the front of the queue. 
If the required page is not in memory, we bring that in memory. In simple words, we add a new node to the front of the queue and update the corresponding node address in the hash. If the queue is full, i.e. all the frames are full, we remove a node from the rear of the queue, and add the new node to the front of the queue.

Example – Consider the following reference string :  

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
Find the number of page faults using least recently used (LRU) page replacement algorithm with 3 page frames. 

*/

class LRUCache {
    private class DoublyLinkedList {
        int key;
        int value;
        DoublyLinkedList prev;
        DoublyLinkedList next;
        
        DoublyLinkedList(int key,int value) {
            this.key = key;
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }
    
    HashMap<Integer,DoublyLinkedList> map;
    DoublyLinkedList head,tail;
    int size;

    public LRUCache(int capacity) {
        size = capacity;
        map = new HashMap<>();
        head = null;
        tail = null;
    }
    
    private void removeFromDoublyLinkedList(DoublyLinkedList node) {
        if(map.size() == 1) {
            head = null;
            tail = null;
        } else if(head == node) {
            DoublyLinkedList hNode = head;
            head = head.next;
            hNode.prev = null;
            hNode.next = null;
        } else if(tail == node) {
            DoublyLinkedList tNode = tail;
            tail = tail.prev;
            tNode.prev = null;
            tNode.next = null;
        } else {
            DoublyLinkedList prevNode = node.prev;
            DoublyLinkedList nextNode = node.next;
            
            prevNode.next = nextNode;
            nextNode.prev = prevNode;
            node.prev = null;
            node.next = null;
        }
        
        map.remove(node.key);
    }
    
    private void addToDoublyLinkedList(DoublyLinkedList node) {
        if(head == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = tail.next;
        }
        
        map.put(node.key,node);
    }
    
    public int get(int key) {
        if(map.containsKey(key)) {
            DoublyLinkedList node = map.get(key);
            removeFromDoublyLinkedList(node);
            addToDoublyLinkedList(node);
            
            return node.value;
        }
        
        return -1;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)) {
            int val = get(key);
            
            if(val != value) {
                this.tail.value = value;
            }
        } else {
            DoublyLinkedList node = new DoublyLinkedList(key,value);
            
            if(map.size() == size) {
                removeFromDoublyLinkedList(head);
                addToDoublyLinkedList(node);
            } else {
                addToDoublyLinkedList(node);
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */



// ---------------------------------------------------------------------

// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
	// store keys of cache
	list<int> dq;

	// store references of key in cache
	unordered_map<int, list<int>::iterator> ma;
	int csize; // maximum capacity of cache

public:
	LRUCache(int);
	void refer(int);
	void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
	csize = n;
}

// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
	// not present in cache
	if (ma.find(x) == ma.end()) {
		// cache is full
		if (dq.size() == csize) {
			// delete least recently used element
			int last = dq.back();

			// Pops the last elmeent
			dq.pop_back();

			// Erase the last
			ma.erase(last);
		}
	}

	// present in cache
	else
		dq.erase(ma[x]);

	// update reference
	dq.push_front(x);
	ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display()
{

	// Iterate in the deque and print
	// all the elements in it
	for (auto it = dq.begin(); it != dq.end();
		it++)
		cout << (*it) << " ";

	cout << endl;
}

// Driver Code
int main()
{
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();

	return 0;
}
