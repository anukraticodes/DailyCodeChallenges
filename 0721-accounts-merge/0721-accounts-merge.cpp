class Solution {
public:

vector<int> parent;
vector<int> rank;

void dsu(int n, vector<vector<string>>& a){
parent.resize(n);
rank.resize(n, 0);
for(int i=0; i<n; i++){
    parent[i]=i;
}
}

int findP(int s){
    if(s==parent[s]) return s;
    return parent[s]=findP(parent[s]);
}

void unite(int u, int v){
    int pu=findP(u);
    int pv=findP(v);
    if(rank[pu]>pv){
        parent[pv]=pu;
    }
    else if(rank[pv]>pu){
        parent[pu]=pv;
    }
    else{
        parent[pu]=pv;
        rank[pv]++;
    }
}

    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        dsu(a.size(), a);
        unordered_map<string, int> mp;
        vector<vector<string>> v;
        for(int i=0; i<a.size(); i++){
            for(int j=1; j<a[i].size(); j++){
                string mail=a[i][j];

                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    unite(i, mp[mail]);
                }
            }
        }
        vector<vector<string>> merged(a.size());
        for(auto it:mp){
            string mail=it.first;
            int node=findP(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<a.size(); i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(a[i][0]);
            for(auto it:merged[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;

    }
};