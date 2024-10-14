class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int> pq;
        for(int i=0; i<p.size(); i++){
            pq.push(p[i]);
        }
        
        while(k--){
            int x=pq.top();
            pq.pop();
            
            pq.push((x+1)/2);
        }
        int result=0;
        while(!pq.empty()){
            result+=pq.top();
            pq.pop();
        }
        return result;

    }
};