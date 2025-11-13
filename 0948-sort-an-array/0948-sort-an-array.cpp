class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       mergesort(nums,0, nums.size()-1);
       return nums;
    }

    void mergesort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid=(l+r)/2;
            mergesort(nums, l, mid);
            mergesort(nums, mid+1, r);
            combine(nums, l, r, mid);
        }
    }

    void combine(vector<int>& nums, int l, int r, int mid){
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int> L(n1), R(n2);

        for(int i=0; i<n1; i++) L[i]=nums[l+i];
        for(int j=0; j<n2; j++) R[j]=nums[mid+j+1];
        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]) nums[k++]=L[i++];
            else nums[k++]=R[j++];
        }
        while(i<n1) nums[k++]=L[i++];
        while(j<n2) nums[k++]=R[j++];
    }
};