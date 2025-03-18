class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int l = 0, ans = 0;
        int uniqueCount = 0;

        for (int r = 0; r < word.size(); r++) {
            if (r > 0 && word[r] < word[r - 1]) {
                // Order is broken — reset
                l = r;
                uniqueCount = 0;
            }
            
            if (r == 0 || word[r] != word[r - 1]) {
                uniqueCount++;
            }
            
            if (uniqueCount == 5) {
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};
