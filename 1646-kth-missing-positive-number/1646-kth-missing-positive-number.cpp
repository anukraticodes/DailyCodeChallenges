class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
          int l=0, r=arr.size();
        while(l<r){
            int mid=l+(r-l)/2;
            int miss=arr[mid]-(mid+1);
            if(miss<k) l=mid+1;
            else r=mid;
        }
        return k+l;
    }
};