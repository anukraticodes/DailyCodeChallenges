class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans=0;
        int n=heights.size();
        stack<int> st;
        for(int i=0; i<=n; i++){
            int currh= i==n ? 0 :heights[i];
            while(!st.empty() && heights[st.top()]>currh){
                int height=heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans=max(ans, height*width);
            }
            st.push(i);
        }
        return ans;
    }
};