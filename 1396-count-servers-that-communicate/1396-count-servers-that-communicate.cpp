class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        vector<pair<int, int>> grid;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[0].size(); j++){
                if(g[i][j]==1) grid.push_back({i, j});
            }
        }
        
        int n=grid.size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((grid[i].first==grid[j].first || grid[i].second==grid[j].second)&&(i!=j)){
                    ans++;
                    break;
                }
                
            }
        }
       
        return ans;
    }
};