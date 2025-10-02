class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
                vector<int> st;

        for(int num: nums){
            int curr = num;
            while(!st.empty()){
                int div = gcd(curr, st.back());
                if(div == 1) break;
                curr = curr/div * (st.back());
                st.pop_back();
            }
            st.push_back(curr);
        }
        return st;
    }
};
