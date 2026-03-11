class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int mid=n/2;
        vector<vector<int>> left(mid+1), right(mid+1);
        int sum=accumulate(nums.begin(), nums.end(), 0);
        // int n1=mid, n2=n-mid;

        for(int mask=0; mask<(1<<mid); mask++){
            int s=0, cnt=0;
            for(int i=0; i<mid; i++){
                if(mask&(1<<i)) {s+=nums[i]; cnt++;}
            }
            left[cnt].push_back(s);
        }
        for(int mask=0; mask<(1<<mid); mask++){
            int s=0, cnt=0;
            for(int i=0; i<mid; i++){
                if(mask&(1<<i)){ s+=nums[mid+i]; cnt++;}
            }
            right[cnt].push_back(s);
        }
        for(int i = 0; i <= mid; i++)
            sort(right[i].begin(), right[i].end());
        int ans=INT_MAX;
        for(int k=0; k<=mid; k++){
            for(int l:left[k]){
                int target=sum/2-l;
                auto &vec=right[mid-k];
                auto it=lower_bound(vec.begin(), vec.end(), target);
                if(it!=vec.end()){
                    int s=l+*it;
                    ans=min(ans, abs(sum-2*s));
                }
                if(it!=vec.begin()){
                    it--;
                    int s=l+*it;
                    ans=min(ans, abs(sum-2*s));
                }
            }
        }
        return ans;
    }
};