class Solution {
public:
    // Computes boosted Manhattan component for a direction pair using available changes
    int count(int d1, int d2, int changes) {
        return abs(d1 - d2) + changes * 2;
    }

    int maxDistance(string s, int k) {
        unordered_map<char, int> mp;
        int ans = 0;

        for (char c : s) {
            mp[c]++;
            int ns_changes = min({mp['N'], mp['S'], k});
            int ew_changes = min({mp['E'], mp['W'], k - ns_changes});
            int dist = count(mp['N'], mp['S'], ns_changes) + count(mp['E'], mp['W'], ew_changes);
            ans = max(ans, dist);
        }

        return ans;
    }
};
