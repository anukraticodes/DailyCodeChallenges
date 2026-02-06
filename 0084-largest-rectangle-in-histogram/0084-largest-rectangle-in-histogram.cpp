class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        vector<int> l(n),r(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            l[i]= st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            r[i]=st.empty()?n:st.top();
            st.push(i);
        }
        for(int i=0; i<n; i++){
            ans=max(ans, (r[i]-l[i]-1)*heights[i]);
        }
        return ans;
    }
};