#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Solution{
    public:

    int removeElement(vector<int> &nums, int value){
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=value){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};
int main(){
    int size;
    cout<<"Enter the size of elements : ";
    cin>>size;
    vector<int> nums(size);
    cout<<"Enter the elements in the array : ";
    for(int i = 0 ; i< size;i++){
        cin>>nums[i];
    }
    int value;
    cout<<"Enter the value to be removed : ";
    cin>>value;
    
    Solution sol;
    int k = sol.removeElement(nums,value);
    cout<<"After the Removal of the Value : ";
    for(int i = 0 ; i< k;i++){
        cout<<nums[i];
    }
}