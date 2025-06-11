class Solution {
public:

    long long wonderfulSubstrings(string word) {
        unordered_map<int, long long> mp;
        mp[0]=1;
        long long status=0;
        long long ans=0;
        for(int i=0; i<word.size(); i++){
            int temp=word[i]-'a';
            status=status^(1<<temp);
            if(mp.count(status)) ans += mp[status];
            for(int j=0; j<=9; j++){
              if(mp.count(status^(1<<j))) ans+=mp[status^(1<<j)];
            }
            mp[status]++;
        }
        return ans;
    }
};