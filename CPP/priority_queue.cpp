#include<iostream>
#include<queue>
using namespace std;

int main(){
    //priority<int> pq_max;
    priority_queue<int, vector<int>, greater<int> > pq;// return min first

    for(int i=10 ; i<= 100;i += 10){
        pq.push(i);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
