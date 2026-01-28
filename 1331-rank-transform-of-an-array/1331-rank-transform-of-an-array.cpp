class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        } 
        int n=arr.size();
        vector<int> ans(n);
        int rank=1;
        for(auto it:mp){
            for(auto it2:it.second){
                ans[it2]=rank;
            }
            rank++;
        }
        return ans;
    }
};