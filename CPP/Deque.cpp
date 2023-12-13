#include<iostream>

using namespace std;


// Node Structure for storing Data
template<typename T>
struct node {
	T val;
	node *left,*right;
	node(T v) {
		left=right=NULL;
		val=v;
	}
};

// Deque Class
template<typename T>
class deque {
	// Store front and back pointers
	node<T> *Front,*Back;
	int size;
public:
	// Initialize front and back pointers with NULL since deque is empty
	deque() {
		size = 0;
		Front = Back = NULL;
	}

	// Push in front of deque
	void push_front(T v) {
		node<T> *N = new node<T>(v);
		if(Front) Front->left = N;
		N->right = Front;
		Front = N;
		if(Back==NULL) Back = N; // In case deque was empty
		size++;
		return;
	}

	// Push in back of deque
	void push_back(T v) {
		node<T> *N = new node<T>(v);
		if(Back) Back->right = N;
		N->left = Back;
		Back = N;
		if(Front == NULL) Front = N; // In case deque was empty
		size++;
		return;
	}

	// Empty check for deque
	bool empty() {
		return size==0;
	}

	// Pop element from front
	void pop_front() {
		if(size==0) return; // In case deque is empty
		node<T> *temp = Front;
		Front = Front->right;
		delete temp;
		size--;
		return;
	}

	// Pop element from back
	void pop_back() {
		if(size==0) return; // In case deque is empty
		node<T> *temp = Back;
		Back = Back->left;
		delete temp;
		size--;
		return;
	}

	// Return front element
	T front() {
		if(size==0) return 0; // In case deque is empty
		return Front->val;
	}

	// Return back element
	T back() {
		if(size==0) return 0; // In case deque is empty
		return Back->val;
	}
};

int main() {
	deque<int> dq;
	dq.push_front(10);
	dq.push_back(20);
	cout<<dq.front()<<endl;
	dq.push_front(30);
	cout<<dq.front()<<" "<<dq.back()<<endl;
	return 0;
}