class EventManager {
public:
map<int, set<int>> mp;
unordered_map<int, int> mp2;
    EventManager(vector<vector<int>>& events) {
        for(auto it:events){
            int id=it[0], p=it[1];
            mp[p].insert(id);
            mp2[id]=p;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int p=mp2[eventId];
        mp[p].erase(eventId);
        if(mp[p].empty()) mp.erase(p);
        mp[newPriority].insert(eventId);
        mp2[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(!mp.empty()){
        auto it=mp.rbegin();
        auto k=*it->second.begin();
        it->second.erase(k);
        if(it->second.empty()) mp.erase(it->first);
        mp2.erase(k);
        return k;
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