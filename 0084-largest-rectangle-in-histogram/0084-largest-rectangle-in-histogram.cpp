class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int ans=0;
        int n=h.size();
        for(int i=0; i<=h.size();i++){
            int currh=i==n?0:h[i];
           
           while(!st.empty() && currh<h[st.top()]){
            int he=h[st.top()];
            st.pop();
            int d=-1;
            if(!st.empty()) d=st.top();
            ans=max(ans, (i-d-1)*he);
           }
           st.push(i);
        }
        return ans;
    }
};