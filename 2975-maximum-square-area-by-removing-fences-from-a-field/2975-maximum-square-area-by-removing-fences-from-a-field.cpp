class Solution {
public:
const long long MOD = 1000000007;

    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        unordered_set<int> st;
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(v.begin(), v.end());
        sort(h.begin(), h.end());
        int ans=-1;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                st.insert(abs(v[i]-v[j]));
            }
        }
        for(int i=0; i<h.size(); i++){
        // if (h.back() - h[i] <= ans) break;

            for(int j=i+1; j<h.size(); j++){
               

               if(st.find(abs(h[j]-h[i]))!=st.end()){
                ans=max(ans, abs(h[j]-h[i]));
               }
            }
        }
        if(ans==-1) return -1;
        return ( (ans % MOD) * (ans % MOD) ) % MOD;

    }
};