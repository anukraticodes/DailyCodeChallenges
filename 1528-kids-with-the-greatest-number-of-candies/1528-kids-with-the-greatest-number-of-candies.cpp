class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int val=*max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size(), 0);
        for(int i=0; i<candies.size(); i++){
            if(extra+candies[i]>=val) ans[i]=1;
        }
        return ans;
    }
};