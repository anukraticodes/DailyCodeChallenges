class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0; i<=n; i++){
            int h=(i==n)?0:heights[i];
            while(!st.empty() && h<heights[st.top()]){
                int he=heights[st.top()];
                st.pop();
                ans=max(ans, he*(st.empty()?i:i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};