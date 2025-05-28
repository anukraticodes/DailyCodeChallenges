class Solution {
public:

    vector<int> helper(const vector<vector<int>>& adj, const int k){
        vector<int> ans;
        for(int i=0; i<adj.size(); i++){
            queue<pair<int, int>> q;
            q.push({i, -1});
            int vals=0;
            int rem=k;
            while(!q.empty() && rem>=0){
                int qsize=q.size();
                for(int j=0; j<qsize; j++){
                    int node=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    ++vals;
                    for(const int& nbr:adj[node]){
                        if(nbr==parent) continue;
                        q.push({nbr, node});
                    }
                }
                rem--;
            }
            ans.push_back(vals);
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> adj1(edges1.size()+1);
        for(const vector<int>& edge: edges1){
            adj1[edge.front()].emplace_back(edge.back());
            adj1[edge.back()].emplace_back(edge.front());
        }
        vector<vector<int>> adj2(edges2.size()+1);
        for(const vector<int>& edge:edges2){
            adj2[edge.front()].emplace_back(edge.back());
            adj2[edge.back()].emplace_back(edge.front());
        }
        vector<int> ans=helper(adj1, k);
        vector<int> v=helper(adj2, k-1);
        int val=*max_element(v.begin(), v.end());
        for(int& num:ans) num+=val;
        return ans;
    }
};