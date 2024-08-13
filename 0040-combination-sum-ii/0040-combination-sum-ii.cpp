class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> v;
        vector<int> ds;
        func(0, target, candidates, v, ds);
        return v;
    }

    void func(int index, int target, vector<int> & arr, vector<vector<int>>& v, vector<int> & ds){
        if(target==0) { v.push_back(ds); return;}

        for(int i=index; i<arr.size(); i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            func(i+1, target-arr[i], arr, v, ds);
            ds.pop_back();
        }
    }
};