// Question Link: https://leetcode.com/problems/split-array-largest-sum/

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int s = *max_element(nums.begin(), nums.end());
        int e = 0;
        for (int i : nums)
            e += i;
        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            int p = 0;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                if (sum > mid)
                {
                    sum = nums[i];
                    p++;
                }
            }
            if (p < m)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};