class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        unordered_map<string, int> mp;
        for (string s : w) mp[s]++;

        int cnt = 0;
        bool hasMiddle = false;

        for (auto& it : mp) {
            string word = it.first;
            int freq = it.second;

            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                
                cnt += (freq / 2) * 4;
                if (freq % 2) hasMiddle = true;
            } else if (word < rev && mp.count(rev)) {
                cnt += min(freq, mp[rev]) * 4;
            }
        }

        if (hasMiddle) cnt += 2;

        return cnt;
    }
};
