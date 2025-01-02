class Solution {
public:

    bool isvowel(string s){
        return ((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&&(s[s.size()-1]=='a'||s[s.size()-1]=='e'||s[s.size()-1]=='i'||s[s.size()-1]=='o'||s[s.size()-1]=='u'));
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // for(int i=0; i<words.size(); i++){
        //     if(isvowel(words[i]))
        //     words[i]="1";
        //     else words[i]="0";
        // }
        vector<int> cnt(words.size());
        int sum=0;
        for(int i=0; i<words.size(); i++){
             if(isvowel(words[i])) sum++;
             cnt[i]=sum;
        }
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            int cnt1;
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0) cnt1=cnt[r];
            else cnt1=cnt[r]-cnt[l-1];
            ans[i]=cnt1;
        }
        return ans;
    }
};