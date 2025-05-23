class Solution {
public:
    bool closeStrings(string w1, string w2) {
        set<char> charw1, charw2;
        vector<int> freqw1(26, 0), freqw2(26, 0);
        for(auto c:w1){
            charw1.insert(c);
            freqw1[c-'a']++;
        }
        for(auto c:w2){
            charw2.insert(c);
            freqw2[c-'a']++;
        }
        map<int, int> st1, st2;
        for(auto n:freqw1){
            if(n!=0){
                st1[n]++;
            }
        }
        for(auto n:freqw2){
            if(n!=0){
                st2[n]++;
            }
        }
        return charw1==charw2 && st1==st2;
    }
};