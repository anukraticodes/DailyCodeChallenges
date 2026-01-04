class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto it:words) mp[it]++;
        int x=words[0].size();
        int tot=words.size();
        vector<int> ans;
        for(int i=0; i<x; i++){
            int l=i, cnt=0;
            unordered_map<string, int> mp2;
            for(int r=i; r+x<=s.size(); r+=x){
                string curr=s.substr(r, x);
                if(mp.count(curr)){
                mp2[curr]++;
                cnt++;
                while(mp2[curr]>mp[curr]){
                    string lw=s.substr(l,x);
                    mp2[lw]--;
                    cnt--;
                    l+=x;
                }
                if(cnt==tot) ans.push_back(l);
                }
                else{
                    cnt=0;
                    l=r+x;
                    mp2.clear();
                }
            }
        }
        return ans;
    }
};