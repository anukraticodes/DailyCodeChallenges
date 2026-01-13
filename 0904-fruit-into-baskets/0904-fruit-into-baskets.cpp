class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> v(fruits.size()+1, 0);
        int l=0, ans=0, cnt=0;
        for(int r=0; r<fruits.size(); r++){
           v[fruits[r]]++;
           if(v[fruits[r]]==1) cnt++;
            while(cnt>2){
                if(v[fruits[l]]==1) {v[fruits[l]]=0; cnt--;}
                else v[fruits[l]]--;
                l++;
            }
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};