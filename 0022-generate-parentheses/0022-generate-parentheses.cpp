class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; helper(0, 0, "", n, ans);
        return ans;
    }

    void helper(int openP, int closeP, string s, int n, vector<string>& ans){
        if(openP==closeP && openP+closeP==2*n){
            ans.push_back(s);
            return;
        }
        if(openP<n) helper(openP+1, closeP, s+"(", n, ans);
        if(closeP<openP) helper(openP, closeP+1, s+")", n, ans);
        // return ans;
    }
};