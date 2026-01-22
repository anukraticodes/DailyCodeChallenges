class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> nums(arr.size());
        for(int i=0; i<arr.size(); i++){
            nums[i]=arr[i]-(i+1);
        }
        int ub=-1;
        helper(nums,k,ub);
        if(ub==0) return k;
        return arr[ub-1]+(k-nums[ub-1]);
    }

    void helper(vector<int>& arr, int k, int& ub){
        int l=0, r=arr.size();
        while(l<r){
            int mid=(l+r)/2;
            if (mid < arr.size() && arr[mid] >= k)
            r = mid;
            else l=mid+1; 
        }
        ub=l;
    }
};