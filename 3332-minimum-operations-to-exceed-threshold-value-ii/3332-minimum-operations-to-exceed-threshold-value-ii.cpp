class Solution {
public:

    void findmin(multiset<long long>& arr){
        // long long x=INT_MAX, y=INT_MAX;
         auto it = arr.begin();
        long long x = *it; ++it;
        long long y = *it;
        
        arr.erase(arr.begin());
        arr.erase(arr.begin()); 
        arr.insert(2 * x + y);      
    }
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> n(nums.begin(), nums.end());
        int cnt=0;
        while (n.size() >= 2 && *n.begin() < k) {
            cnt++;
            findmin(n);  // Perform the operation
        }
        
        return cnt;
    }
};