class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> v(201,0);
        for(int num:nums) v[num+100]++;

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(v[a+100]==v[b+100]) return a>b;
            return v[a+100]<v[b+100];
        });
        return nums;
    }
};