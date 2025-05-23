class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size()) return 0;
        vector<int> freqw1(26, 0), freqw2(26, 0);
        for(int i=0; i<w1.size(); i++){
            freqw1[w1[i]-'a']++;
            freqw2[w2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freqw1[i]==0 && freqw2[i]==0) continue;
            if(freqw1[i]!=0 && freqw2[i]!=0) continue;
            return 0;
        }
        sort(freqw1.begin(), freqw1.end());
        sort(freqw2.begin(), freqw2.end());
        return freqw1==freqw2;
    }
};