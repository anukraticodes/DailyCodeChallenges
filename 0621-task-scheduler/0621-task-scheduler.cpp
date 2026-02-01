class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char, int> mp;
        for (auto it : tasks) {
            mp[it]++;
        }
        for (auto it : mp) {
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty()){
            int cnt=0;
            queue<int> q;
            int iter=n+1;
            while(iter-- && !pq.empty()){
                if(pq.top()>1){
                    q.push(pq.top()-1);
                }
                pq.pop();
                cnt++;
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            time+=(pq.empty()?cnt:n+1);
        }
        return time;
    }
};