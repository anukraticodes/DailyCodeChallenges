class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqs(123,0);
        vector<int> freqt(123,0);
        for(auto c:t) freqt[c]++;
        int l=0, r=0;
        int same=0, ind=-1, minl=s.size()+1;
        while(r<s.size()){
            char c=s[r];
            if(freqs[c]<freqt[c]) same++;
            freqs[c]++;
            while(same==t.size()){
                if(r-l+1<minl){
                    minl=r-l+1;
                    ind=l;
                }
                freqs[s[l]]--;
                if(freqs[s[l]]<freqt[s[l]]) same--;
                l++;
            }
            r++;
        }
        return ind==-1?"":s.substr(ind, minl);
    }
};