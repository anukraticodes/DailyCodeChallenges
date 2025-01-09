class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size(), cnt=0;
        for(int i=0; i<words.size(); i++){
            string s="";
            if(words[i].size()<n) continue;
            for(int j=0; j<n; j++){
                s+=words[i][j];
            }
            if(s==pref) cnt++;
        }
        return cnt;
    }
};