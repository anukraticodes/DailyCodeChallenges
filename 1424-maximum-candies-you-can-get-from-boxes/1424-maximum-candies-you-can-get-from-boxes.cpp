class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& contained, vector<int>& initial) {
        queue<int> q;
        for (auto it:initial) q.push(it);
        int ans=0;
        vector<int> boxes(status.size(), 0);
        while(!q.empty()){
           int box=q.front();
           q.pop();
           boxes[box]=1;
           for(auto it:keys[box]) if(it!=box) status[it]=1;
           for(auto it:contained[box]){
            if(boxes[it]==0) q.push(it);
           }
        }
        for(int i=0; i<status.size(); i++){
            if(status[i]==1 && boxes[i]==1) ans+=candies[i];
        }
        return ans;
    }
};