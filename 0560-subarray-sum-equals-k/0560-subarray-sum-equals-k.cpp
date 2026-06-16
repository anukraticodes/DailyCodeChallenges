class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int cnt=0, sum=0;

        for(int i=0; i<arr.size(); i++){
           sum+=arr[i];

           if(sum==k){
            cnt++;
           }

           if(mp.count(sum-k)){
             cnt+=mp[sum-k];
           }

           mp[sum]++;
        }
        return cnt;
    }
};