class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0; i<nums.size(); i++){
        pq.push({nums[i],i});
    }
    // make_heap(heap.begin(), heap.end(), greater<>());

    while(k--){
        // pop_heap(heap.begin(), heap.end(), greater<>());
        auto[value,i]=pq.top();
        pq.pop();
        nums[i]*=m;
        pq.push({nums[i],i});
        // push_heap(heap.begin(), heap.end(), greater<>());
    }
    return nums;
    }
};