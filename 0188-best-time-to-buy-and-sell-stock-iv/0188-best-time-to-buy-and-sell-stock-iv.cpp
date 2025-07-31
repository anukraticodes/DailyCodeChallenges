class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        vector<vector<int>> ahead(k+1, vector<int>(2, 0)), curr(k+1, vector<int>(2, 0));
        long profit=0;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy==0){
                        profit=max(ahead[cap][buy], -p[i]+ahead[cap][1]);
                    }
                    else{
                        profit=max(ahead[cap][buy], p[i]+ahead[cap-1][0]);
                    }
                    curr[cap][buy]=profit;
                }
            }
            ahead=curr;
        }
        return ahead[k][0];
    }
};