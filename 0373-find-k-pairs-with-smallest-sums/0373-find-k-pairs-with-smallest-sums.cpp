class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>> pq;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
            if(pq.size()<k){
                pq.push({nums1[i]+nums2[j], nums1[i], nums2[j]});
            }
            else{
                auto [sum, a, b]=pq.top();
                if(sum<=nums1[i]+nums2[j]) break;
                pq.pop();
                pq.push({nums1[i]+nums2[j], nums1[i], nums2[j]});
            }
        }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [sum, a, b]=pq.top();
            pq.pop();
            ans.push_back({a, b});
        }
        return ans;
    }
};