class Solution {
public:

set<set<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> v;
        helper(k, n, v, 0, 1);
        vector<vector<int>> res;
        for(auto it:ans){
            vector<int> v2;
            for(auto it2:it){
                v2.push_back(it2);
                // cout<<it2<<" ";
            }
            res.push_back(v2);
            // cout<<endl;
        }
        return res;
    }

    void helper(int k, int n, set<int> v, int sum, int start){
        if(v.size()>k || sum>n) return;

        if(sum==n && v.size()==k){
            ans.insert(v);
            return;
        }
        for(int i=start; i<=9; i++){
            v.insert(i);
            helper(k, n, v, sum+i, i+1);
            v.erase(i);
        }
    }
};