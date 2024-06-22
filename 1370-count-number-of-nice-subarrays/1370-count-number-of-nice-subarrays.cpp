class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // To handle subarrays that start from the beginning
    int prefixSum = 0;
    int niceSubarrays = 0;
    
    for (int num : nums) {
        // Update prefix sum based on whether the current number is odd or even
        prefixSum += (num % 2);
        
        // Check if there's a previous prefix sum that matches the current sum - k
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            niceSubarrays += prefixSumCount[prefixSum - k];
        }
        
        // Update the count of the current prefix sum in the hash map
        prefixSumCount[prefixSum]++;
    }
    
    return niceSubarrays;
}

};