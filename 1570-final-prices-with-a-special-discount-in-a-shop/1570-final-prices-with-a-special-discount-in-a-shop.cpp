class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        stack<int> st;
        int n=p.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && p[i]<=p[st.top()]){
                int ind=st.top();
                st.pop();
                p[ind]-=p[i];
            }
            st.push(i);
        }
        return p;
    }
};