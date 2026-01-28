class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0; i<arr.size(); i++){
            pq.push({arr[i],i});
        } 
        int rank=1;
  
        vector<int> ans(arr.size());
        while(!pq.empty()){
            auto[curr, ind]=pq.top();
            pq.pop();
            ans[ind]=rank;
            if(pq.top().first!=curr)rank++;
        }
        return ans;
        
    }
};