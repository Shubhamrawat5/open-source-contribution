class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
       stack<int> st;
        int n=heights.size(),i,res=INT_MIN,tp,right,width,left,area;
        
        for(i=0;i<n;i++)
        {
            // keep popping >=numbers
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                // Calculate the histogram
                tp=st.top();
                st.pop();
                
                right = i;
                left = st.empty()?-1 : st.top();
                
                width = right-left-1;
                
                area = width*heights[tp];
                
                res = max(res,area);
            }
            st.push(i);
        }
       
        return res;
    }
};