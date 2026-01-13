class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l=0, ans=0;
        for(int r=0; r<fruits.size(); r++){
            mp[fruits[r]]++;
            while(mp.size()>2 && l<=r){
                if(mp[fruits[l]]==1) mp.erase(fruits[l]);
                else mp[fruits[l]]--;
                l++;
            }
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};