class Solution {
public:

vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        helper(k, n, v, 1);
        
        return res;
    }

    void helper(int k, int n, vector<int>& v, int start){
        // if(v.size()>k || start>n) return;

        if(v.size()==k && n==0){
            res.push_back(v);
            return;
        }
        for(int i=start; i<=9; i++){
            
            v.push_back(i);
            helper(k, n-i, v, i+1);
            v.pop_back();
        }
    }
};