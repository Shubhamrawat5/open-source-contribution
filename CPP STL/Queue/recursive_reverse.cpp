// Reverse a queue ( Recursive solution )
#include<iostream>
#include<queue>         // Header file of queue
using namespace std;

/*  IDEA :- 
    Example - Let q = {2,4,5,0,1}
    What we do is keep the front element in a temporary variable and pop it.
    Let temp = 2 and we will have q = {4,5,0,1}. Now we recursively reverse the q.
    Then we will have q = {1,0,5,4}. After this we push the value in the temporary
    variable in the queue. So we will get q = {1,0,5,4,2} which is the required 
    reversed queue.
*/
void reverse_recursive(queue <int> &q){
    if(q.empty())       // Base Case
        return;
    
    int temp = q.front();       // First inserted element
    q.pop();                    // Remove the first inserted element
    reverse_recursive(q);
    /* We recursively reverse the remaining elements of the queue.
       If our assumption is right regarding the function, i.e it 
       works perfectly and reverses the given input queue, then 
       after the above statement is executed, the remaining queue
       which was given as input must have been reversed. 
    */       
    q.push(temp);
    /* Now we just push the element at the back of the queue, which 
       was stored in 'temp'.
    */
}

int main(){
    queue <int> q;
    queue <int> temp;
    q.push(2);
    q.push(4);
    q.push(5);
    q.push(0);
    q.push(1);
    // Example queue - {2,4,5,0,1}
    temp = q;
    cout<<"Original queue : ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
    q = temp;
    reverse_recursive(q);       // Calling the reverse function
    cout<<"Reversed queue : ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}