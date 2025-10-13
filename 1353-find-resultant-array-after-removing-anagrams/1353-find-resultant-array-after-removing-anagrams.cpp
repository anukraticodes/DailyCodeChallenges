class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        if (n == 0) return ans;

        ans.push_back(words[0]); 

        for (int i = 1; i < n; i++) {
            unordered_map<char, int> mp1, mp2;
            for (auto ch : words[i]) mp2[ch]++;
            for (auto ch : words[i - 1]) mp1[ch]++;
            if (mp1 != mp2) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
