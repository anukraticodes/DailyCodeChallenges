class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]]={i, j};
            }
        }
        for(int i=0; i<arr.size(); i++){
            rows[mp[arr[i]].first]++;
            cols[mp[arr[i]].second]++;
            if(rows[mp[arr[i]].first]==m) return i;
            if(cols[mp[arr[i]].second]==n) return i;
        }
        return -1;

    }
};