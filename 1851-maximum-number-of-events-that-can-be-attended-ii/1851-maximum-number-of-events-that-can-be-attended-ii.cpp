class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n=events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return dfs(0, k, dp, events);   
    }

    int dfs(int ind, int k, vector<vector<int>>& dp, vector<vector<int>>& events){
        if(k==0 || ind==events.size()) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int nottake=dfs(ind+1, k, dp, events);
        int next=ub(events[ind][1], events);
        int take=events[ind][2]+dfs(next, k-1, dp, events);
        return dp[ind][k]=max(nottake, take);
    } 

    int ub(int ind, vector<vector<int>>& events){
           int low=0, high=events.size();
           while(low<high){
            int mid=(low+high)/2;
            if(events[mid][0]>ind) high=mid;
            else{ low=mid+1;}
           }
           return low;
    }
};