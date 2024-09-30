class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt=0;
        mergeSort(nums, 0, nums.size()-1, cnt);
        return cnt;
    }

    void mergeSort(vector<int>& nums, int low, int high, int& cnt){
        if(low<high){
            int mid=(low+high)/2;
            mergeSort(nums, low, mid, cnt);
            mergeSort(nums, mid+1, high, cnt);
            merge(nums, low, mid, high, cnt);
        }
    }

    void merge(vector<int>& nums, int low, int mid, int high, int& cnt){
       int j=mid+1;
       for(int i=low; i<=mid; i++){
        while(j<=high && nums[i]>2*(long long)nums[j]) j++;
        cnt+=j-(mid+1);
       }
       int size=high-low+1;
       vector<int> temp(size, 0);
       int left=low, right=mid+1, k=0;
       while(left<=mid && right<=high){
        if(nums[left]<nums[right]){
            temp[k++]=nums[left++];
        }
        else temp[k++]=nums[right++];
       }

       while(left<=mid) temp[k++]=nums[left++];
       while(right<=high) temp[k++]=nums[right++];
       int m=0;
       for(int i=low; i<=high; i++) nums[i]=temp[m++];


    }



};