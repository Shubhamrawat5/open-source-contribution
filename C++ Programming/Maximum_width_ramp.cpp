class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || nums[i]<nums[st.top()]){
                 st.push(i);
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty() && st.top()>i) break;
            while(!st.empty() && nums[i]>=nums[st.top()])
            {
                ans=max(ans,i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};