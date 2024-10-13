class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(), v.end());
          unordered_map<int, int> freq;  // Frequency map to track list indices
        int l = 0, count = 0;  // `count` tracks how many unique lists are in the window
        int ans = INT_MAX;
        vector<int> result(2);

        for (int r = 0; r < v.size(); r++) {
            if (freq[v[r].second]++ == 0) {
                count++;  // New list added to the window
            }

            // Shrink the window as long as all lists are covered
            while (count == nums.size()) {
                if (v[r].first - v[l].first < ans) {
                    ans = v[r].first - v[l].first;
                    result[0] = v[l].first;
                    result[1] = v[r].first;
                }

                // Remove the leftmost element from the window
                if (--freq[v[l].second] == 0) {
                    count--;  // A list is no longer covered
                }
                l++;  // Move left pointer forward
            }
        }

        return result;
    }
};