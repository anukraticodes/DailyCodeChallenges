class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> mp;
        int status = 0, ans = 0;
        mp[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            status = status ^ (1 << (c - '0'));
            if (mp.count(status)) {
                ans = max(ans, i - mp[status]);
            }

            for (int j = 0; j <= 9; j++) {
                if (mp.count(status ^ (1 << j)))
                    ans = max(ans, i- mp[status ^ (1 << j)]);
            }

            if (!mp.count(status)) {
                mp[status] = i;
            }
        }

        return ans;
    }
};