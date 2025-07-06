class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2; // frequency of nums2 elements

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        int old_val = nums2[index];
        freq2[old_val]--;
        if (freq2[old_val] == 0) {
            freq2.erase(old_val);
        }
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (int a : nums1) {
            int complement = tot - a;
            if (freq2.count(complement)) {
                cnt += freq2[complement];
            }
        }
        return cnt;
    }
};
