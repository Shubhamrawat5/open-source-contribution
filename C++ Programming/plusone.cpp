#include<bits/stdc++.h>
using namespace std;

class Solution{
    public : 
    vector<int> plusone(vector<int>& array){
        for(int n = array.size()-1;n>=0;n--){
            ++array[n];
            array[n]%=10;
            if(array[n]!=0){
                return array;
            }
        }
        array.insert(array.begin(),1);
        return array;
    }
};
int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    vector<int> array(size);
    cout<<"Enter the elements in array : ";
    for(int i = 0 ; i< size;i++){
        cin>>array[i];
    }
    
    Solution sol;
    sol.plusone(array);
    cout<<"Modified array : ";
    for(int i = 0; i<array.size();i++){
        cout<<array[i]<<" ";
    }
    return 0;
}