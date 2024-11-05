#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
class Solution
{
    public :
            int removeDuplicate(vector<int> &nums)
            {
                int n=nums.size();
                if(n==0)
                {
                    return 0;
                }
                int k=1;
                for(int i =0 ;i < n ; i++)
                {
                    if(nums[i] != nums[k-1])
                    {
                        nums[k]=nums[i];
                        k++;
                    }
                }
                return k;
            }   
};
int main(){
    int n=0;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements in the array : ";
    for(int i =0 ; i< n;i++)
    {
        cin>>nums[i];
    }
    Solution sol;
    int k= sol.removeDuplicate(nums);
    cout<<"Unique Elements : "<<k<<endl;
    cout<<"Modefied array : ";
    for(int i =0;i<k;i++){
        cout<<nums[i];
    }
}