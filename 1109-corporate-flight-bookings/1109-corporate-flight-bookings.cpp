class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> diff(n+1, 0);
        for(int i=0; i<b.size(); i++){
            int l=b[i][0], r=b[i][1], num=b[i][2];
            diff[l-1]+=num;
            diff[r]-=num;
        }
        vector<int> ans(n);
        int sum=0;
        for(int i=0; i<diff.size()-1; i++){
           sum+=diff[i];
           ans[i]=sum;
        }
        return ans;
    }
};