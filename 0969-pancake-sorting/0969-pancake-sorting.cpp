class Solution {
public:
    bool issorted(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1])
                return 0;
        }
        return 1;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        int k = n + 1;
        vector<int> ans;
        while (k--) {
            if (issorted(arr))
                break;
            int ind = find(arr.begin(), arr.end(), k)-arr.begin();
            reverse(arr.begin(), arr.begin() + 1 + ind);
            reverse(arr.begin(), arr.begin() + k);
            ans.push_back(ind + 1);
            ans.push_back(k);
        }
        return ans;
    }
};