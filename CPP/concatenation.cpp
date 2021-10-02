//Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.


#include<bits/stdc++.h>
using namespace std;

int numOfPairs(vector<string>& nums, string target) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(nums[i]+nums[j]==target) ans++;
            }
        }
        return ans;
    }
int main()
{
    
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    string target;
    cin>>target;
    int ans=numOfPairs(v,target);
    cout<<ans<<endl;
    return 0;
}



//Example:

//Input: nums = ["777","7","77","77"], target = "7777"
//Output: 4
//Explanation: Valid pairs are:
//- (0, 1): "777" + "7"
//- (1, 0): "7" + "777"
//- (2, 3): "77" + "77"
//- (3, 2): "77" + "77"

