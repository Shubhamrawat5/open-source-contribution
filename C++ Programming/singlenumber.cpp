#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
    int singleNumber(vector<int> &array){
        int ans=0;
        for(int i=0;i<array.size();i++){
            ans^=array[i];
        }
        return ans;
    }
};

int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int> array(size);
    cout<<"Enter the elements in array : ";
    for(int i = 0 ; i < size; i++){
        cin>>array[i];
    }
    
    Solution sol;
    cout<<"Single Number : "<<sol.singleNumber(array);
}