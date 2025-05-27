class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> keys;
        int curr=0;
        queue<int> q;
        q.push(0);
        vector<bool> vis(rooms.size(), 0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(auto it:rooms[curr]){
                if(!vis[it]) q.push(it);
            }
        }
        for(auto it:vis) if(it==false) return 0;
        return 1;
    }
};