class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for(int i=0; i<word.size(); i++){
            mp[word[i]]++;
        }
        
        vector<char> v;
        for(auto ch: mp){
            v.push_back(ch.first);
        }
        sort(v.begin(), v.end(), [&](char a, char b){
            if(mp[a] != mp[b]) return mp[a] > mp[b]; 
            else return a < b;
        });

        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        int i=1, j=1;
        int cnt=1*mp[v[0]];
        while(i<v.size()){
            if(i%8==0) j++;
            cnt+=j*mp[v[i]];
            i++;
        }
        return cnt;
    }
};