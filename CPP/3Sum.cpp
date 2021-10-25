//Leetcode Probelem statement: https://leetcode.com/problems/3sum/
//runtime: 52 ms

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3)
            return {};
        
        int n = nums.size();
        
        // Sort the nums[]
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        
        int first, second, third;
        
        for(int i = 0; i < n; i++) 
        {

            first = nums[i];
            int left = i + 1, right = n - 1;
          
            while(left < right)
            {                
                second = nums[left];
                third = nums[right];               
                if(first + second + third == 0) 
                {
                    ans.push_back({first, second, third});
                    while(left <= right && second == nums[left])
                        left++;
                    while(right >= left && third == nums[right])
                        right--;
                }
                else if(first + second + third < 0)
                    left++;    
                else
                    right--;
            }
            
            while(i < n-1 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};