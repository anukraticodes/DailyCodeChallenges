class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);

        for (char ch : s) {
            freq[ch]++;
        }

        vector<int> a;
        for (int i = 0; i < 128; i++) {
            if (freq[i] != 0) a.push_back(i);
        }

        sort(a.begin(), a.end(), [&](int b, int c) {
            return freq[b] > freq[c];
        });

        string ans = "";
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < freq[a[i]]; j++) {
                ans += (char)a[i];
            }
        }
        
        return ans;
    }
};
