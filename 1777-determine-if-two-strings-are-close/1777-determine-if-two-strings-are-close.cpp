class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.size()!=w2.size()) return 0;
        set<char> charw1, charw2;
        vector<int> freqw1(26, 0), freqw2(26, 0);
        for(int i=0; i<w1.size(); i++){
            charw1.insert(w1[i]);
            freqw1[w1[i]-'a']++;
            charw2.insert(w2[i]);
            freqw2[w2[i]-'a']++;
        }
        map<int, int> st1, st2;
        for(int i=0; i<26; i++){
            if(freqw1[i]!=0){
                st1[freqw1[i]]++;
            }
            if(freqw2[i]!=0){
                st2[freqw2[i]]++;
            }
        }
        return charw1==charw2 && st1==st2;
    }
};