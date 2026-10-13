class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for(int i=0; i<mat.size()&& i<k; i++){
            pq.push({mat[i][0], i, 0});
        }
        int ans=0;
        while(k--){
           auto [val, a, b]=pq.top();
           ans=val;
           pq.pop();
           
           if(b+1<mat[0].size()){
            pq.push({mat[a][b+1], a, b+1});
           }
        }
        return ans;
    }
};