class Solution {
public:

   int bs(vector<int>& res, int num){
    int left=0, right=res.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(res[mid]==num) return mid;
        if(res[mid]>num) right=mid-1;
        else left=mid+1;
    }
    return left;
   }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int n:nums){
            if(res.empty() || res.back()<n){
                res.push_back(n);
            }
            else{
                int ind=bs(res, n);
                res[ind]=n;
            }
        }
        return res.size();
    }
};