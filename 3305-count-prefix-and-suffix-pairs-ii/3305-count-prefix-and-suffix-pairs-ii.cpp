class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<int64_t, int> freq;
        int64_t ans=0, mod=(int64_t)1e17+3;
        for(auto& w : words){
            int64_t l_hash=0, r_hash=0, pow=1;
            for(int n=w.size(), i=1; i<=n; i++){
                l_hash=(l_hash*27LL+(1LL+w[i-1]-'a'))% mod;
                r_hash = ((1LL + w[n - i] - 'a') * pow % mod + r_hash) % mod;
                pow=pow*27%mod;
                if(l_hash==r_hash){
                    auto it=freq.find(l_hash);
                    if(it!=freq.end()) ans+=it->second;
                }
            }
            ++freq[l_hash];
        }
        return ans;
    }
};