class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[1]=ahead[0]=0;
        long profit=0;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0){
                  profit=max(ahead[0], -p[i]+ahead[1]);
                }
                else{
                   profit=max(ahead[1], p[i]+ahead[0]);
                }
               curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[0];
    }
};