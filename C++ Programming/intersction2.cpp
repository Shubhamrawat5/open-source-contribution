#include<iostream>
#include<iomanip>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        vector<int> intersection(vector<int>& num1,vector<int>& num2){
            sort(num1.begin(),num1.end());
            sort(num2.begin(),num2.end());
            vector<int>result;
            int i=0,j=0;
            while(i<num1.size()&&j<num2.size()){
                if(num1[i]>num2[j]){
                    j++;
                }
                else if(num1[i]<num2[j]){
                    i++;
                }
                else{
                    result.push_back(num1[i]);
                    i++;
                    j++;
                }
            }
            return result;
        }
};

int main(){
    int size1;
    int size2;
    cout<<"Enter the sizes of 2 array : ";
    cin>>size1>>size2;
    vector<int> num1(size1);
    vector<int> num2(size2);
    cout<<"Enter the elements in first array : ";
    for(int i = 0 ; i < size1 ; i++){
        cin>>num1[i];
    }
    
    cout<<"Enter the elements in second array : ";
    for(int i = 0 ; i < size2 ; i++){
        cin>>num2[i];
    }
    Solution sol;
    vector<int> k=sol.intersection(num1,num2);
    cout<<"Intersection of arrays: ";
    for(int result : k){
        cout<<result<<" ";
    }
}