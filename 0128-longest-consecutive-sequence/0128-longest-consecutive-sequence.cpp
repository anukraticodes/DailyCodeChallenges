class Solution {
public:
    struct DSU{
        vector<int> parent, rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0; i<n; i++) parent[i]=i;
        }

        int findP(int u){
            if(parent[u]!=u) return parent[u]=findP(parent[u]);
            return parent[u]; 
        }

        void unionD(int u, int v){
            int pu=findP(u), pv=findP(v);
            if(pu==pv) return;
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu]){
                parent[pu]=pv;
            }
            else{
                parent[pu]=pv;
                rank[pv]++;
            }
        }
    };
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]=i;
        unordered_set<int> st;
        int n=nums.size();
        DSU dsu(n);
        for(int i=0; i<nums.size(); i++){
            int num=nums[i];
            if(st.count(num)) continue;
            if(mp.count(num-1)) dsu.unionD(mp[num], mp[num-1]);
            if(mp.count(num+1)) dsu.unionD(mp[num], mp[num+1]);
            st.insert(num);
        }
        vector<int> ans(n+1, 0);
        for(auto it:mp){
            int p=dsu.findP(it.second);
            cout<<p<<endl;
            ans[p]++;
        }
        return *max_element(ans.begin(), ans.end());
    }
};