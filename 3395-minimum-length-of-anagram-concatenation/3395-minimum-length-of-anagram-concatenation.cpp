class Solution {
public:
    bool helper(string s, int k, vector<vector<int>>& v) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < 26; i++) {
            freq[i] = v[i][n - 1] - (n - k - 1 >= 0 ? v[i][n - k - 1] : 0);
        }

        for (int i = n - k - 1; i >= 0; i -= k) {
            vector<int> freq2(26, 0);
            for (int j = 0; j < 26; j++) {
                freq2[j] = v[j][i] - (i - k >= 0 ? v[j][i - k] : 0);
            }
            if (freq != freq2)
                return 0;
        }
        return 1;
    }

    int minAnagramLength(string s) {
        int n = s.size();
        vector<vector<int>> mp(26, vector<int>(s.size(), 0));
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                    mp[j][i] = mp[j][i - 1];
                }
            }
            mp[s[i] - 'a'][i]++;
        }
        for (int i = 1; i < n; i++) {
            if (n % i == 0 && helper(s, i, mp))
                return i;
        }
        return n;
    }
};