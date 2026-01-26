class Solution {
public:
    int helper(vector<int>& arr, const int v){
       int l=0, r=arr.size();
       int ans=0;
       while(l<r){
         int mid=(l+r)/2;
         if(arr[mid]>v) {r=mid;}
         else l=mid+1;
       }
       return l;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        for(int i=0; i<arr.size(); i++){
            sort(arr[i].begin(), arr[i].end());
        }
        int n=arr.size(), m=arr[0].size();
        int ans=0;
        vector<int> ret{0,0};

        for(int i=0; i<n; i++){
            int up=helper(arr[i], 0);
            if(m-up>ans){
                ans=m-up;
              ret={i, ans};
            }

        }
        return ret;
    }
};