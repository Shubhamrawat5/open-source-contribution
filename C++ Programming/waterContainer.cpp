#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0,rp=height.size()-1,maxWater=0;
        while(lp<rp){
            int w=rp-lp;
            int h=min(height[lp],height[rp]);
            int currWater=w*h;
            maxWater=max(maxWater,currWater);

            height[lp]<height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};
int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example heights

    Solution sol;
    int result = sol.maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}