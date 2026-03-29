class EventManager {
public:
priority_queue<pair<int, int>> pq;
unordered_map<int, int> mp;
    EventManager(vector<vector<int>>& events) {
        for(auto it:events){
            int id=it[0], p=it[1];
            pq.push({p, -id});
            mp[id]=p;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
        auto[p, id]=pq.top();
        int nid=-id;

        if(mp.count(nid) && mp[nid]==p){
            pq.pop();
            mp.erase(nid);
            return nid;
        }
        pq.pop();
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */