class Solution {
public:
    int numberOfWays(string c) {
        int seats=0;
        for(auto ch:c) if(ch=='S') seats++;
        cout<<seats<<endl;
        if(seats%2 || seats==0) return 0;
        bool first=1, needfst=1, needsnd=0;
        int currind;
        vector<int> v;
        int req=(seats/2)-1;
        for(int i=0; i<c.size(); i++){
            if(v.size()==req) break;
            if(c[i]=='S' && first){first=0;continue; }
            else if(c[i]=='S' && needfst){
                currind=i;
                needsnd=1;
                needfst=0;
            }
            else if(c[i]=='S' && needsnd){
                int p=i-currind;
                v.push_back(p);
                needsnd=0;
                needfst=1;
            }
        }
        for(auto x:v) cout<<x<<" ";
        int ans=1;
        const long long MOD = 1000000007; 

for (int i = 0; i < v.size(); i++) {
    long long mul = v[i] % MOD;
    ans = (ans * mul) % MOD;
}
cout<<endl;
cout<<ans<<endl;
        return ans%MOD;
    }
};