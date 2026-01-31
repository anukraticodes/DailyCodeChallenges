class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for (auto it : tasks) {
            mp[it]++;
        }
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        int time = 0;
        unordered_map<char, int> curr;
        set<char> banned;
        queue<pair<int, char>> q;
        while (!pq.empty()) {

            for (auto it = curr.begin(); it != curr.end();) {
                it->second--;
                if ((it->second) == 0) {
                    banned.erase(it->first);
                    it = curr.erase(it);         
                } else {
                    ++it;
                }
            }
            // auto [f, c] = pq.top();
            while(! pq.empty() && banned.count(pq.top().second)){
              auto it=pq.top();q.push(it); pq.pop();
              }
              auto [f, c] = pq.top();
            if (!curr.count(c) && !banned.count(c)){
                pq.pop();
                if (f>1) {
                    curr[c] = n+1;
                    banned.insert(c);
                    pq.push({f - 1, c});
                }       
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            time++;
            }
            
        
        return time;
    }
};