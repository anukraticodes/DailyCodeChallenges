class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0]=-1;
        int status=0;
        int ans=INT_MIN;
        for(int i=0; i<s.size(); i++){
            char c=s[i];
            if(c=='a') status^=(1<<0);
            else if(c=='e') status^=(1<<1);
            else if(c=='i') status^=(1<<2);
            else if(c=='o') status^=(1<<3);
            else if(c=='u') status^=(1<<4);

            if(mp.count(status))
                ans=max(ans, i-mp[status]);
            else mp[status]=i;
        }
        return ans==INT_MIN?0:ans;
    }
};