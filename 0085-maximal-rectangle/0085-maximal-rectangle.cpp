class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> hist(m, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') hist[j]++;
                else hist[j]=0;
            }
            ans=max(ans, helper(hist));
        }
        return ans;
    }

    int helper(vector<int>& hist){
        int n=hist.size();
        stack<int> st;
        int ans=0;

        for(int i=0; i<=n; i++){
            int h=(i==n)?0:hist[i];
            while(!st.empty() && hist[st.top()]>h){
                int he=hist[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                ans=max(ans, he*width);
            }
            st.push(i);
        }
        return ans;
    }
};