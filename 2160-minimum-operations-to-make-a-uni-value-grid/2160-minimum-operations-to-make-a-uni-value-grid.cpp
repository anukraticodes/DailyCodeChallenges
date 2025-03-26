class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int val=0;
        // if(v.size()%2!=0) 
        val=(v[v.size()/2]);
        // else{
        //     val=(v[v.size()/2]+v[(v.size()+1)/2])/2;
        // }
        cout<<val<<endl;
        int cnt=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]<val) {
                cnt+=(val-v[i])/x;
                if((val-v[i])%x!=0) return -1;

            }
            else if(v[i]>val) {
                cnt+=(v[i]-val)/x;
            if((v[i]-val)%x!=0) return -1;
            }
        }
        return cnt;
    }
};