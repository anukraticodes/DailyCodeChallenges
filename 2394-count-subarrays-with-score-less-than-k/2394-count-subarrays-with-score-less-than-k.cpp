class Solution {
public:
    long long countSubarrays(vector<int>& arr, long long threshold) {
        int size = arr.size();
        long long count = 0, windowSum = 0;
        int left = 0;
        
        for (int right = 0; right < size; ++right) {
            windowSum += arr[right];
            
            while (left <= right && windowSum * (right - left + 1) >= threshold) {
                windowSum -= arr[left];
                ++left;
            }
            
            count += (right - left + 1);
        }
        
        return count;
    }
};
