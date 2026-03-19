class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for (int k = n; k >= 1; k--) {
            int ind = find(arr.begin(), arr.end(), k)-arr.begin();
            if(ind==k-1) continue;
            if (ind != 0) {
            reverse(arr.begin(), arr.begin() + ind + 1);
            ans.push_back(ind + 1);
        }
        reverse(arr.begin(), arr.begin() + k);
        ans.push_back(k);
        }
        return ans;
    }
};