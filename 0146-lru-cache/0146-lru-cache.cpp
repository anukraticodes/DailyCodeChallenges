class LRUCache {
public:
map<int, list<pair<int, int>>::iterator> mp;
int cap;
list<pair<int, int>> dll;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            auto it=mp[key];
            int val=it->second;
            dll.erase(it);
            dll.push_front({key, val});
            auto it2=dll.begin();
            mp[key]=it2;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto it=mp[key];
            dll.erase(it);
            dll.push_front({key, value});
            auto it2=dll.begin();
            mp[key]=it2;
        }
        else if(mp.size()<cap){
            dll.push_front({key, value});
            auto it=dll.begin();
            mp[key]=it;
        }
        else{
        auto it=dll.back();
        int k=it.first;
        dll.pop_back();
        mp.erase(k);
        dll.push_front({key, value});
        auto it2=dll.begin();
        mp[key]=it2;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */