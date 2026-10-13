class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for (int j = 0; j < nums2.size() && j < k; ++j) {
            pq.push({nums1[0] + nums2[j], 0, j});
        }
        vector<vector<int>> ans;
        while (k > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});
            k--;

            // If there is a next element in the same row (nums1[i], nums2[j + 1]), push it
            if (i + 1 < nums1.size()) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            }
        }
        return ans;
    }
};