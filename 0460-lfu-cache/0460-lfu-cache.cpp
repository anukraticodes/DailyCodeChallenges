class LFUCache {
public:
unordered_map<int, pair<int, int>> mp1;
map<int, list<int>> mp2;
unordered_map<int, list<int>::iterator> mp3;
int cap;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp1.count(key)){
            auto[val, freq]=mp1[key];
            auto it1=mp3[key];
            mp2[freq].erase(it1);
            mp2[freq+1].push_front(key);
            auto it2=mp2[freq+1].begin();
            mp3[key]=it2;
            mp1[key].second=freq+1;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp1.count(key)){
            auto[val, freq]=mp1[key];
            auto it1=mp3[key];
            mp2[freq].erase(it1);
            mp2[freq+1].push_front(key);
            auto it2=mp2[freq+1].begin();
            mp3[key]=it2;
            mp1[key].second=freq+1;
            mp1[key].first=value;
            return;
        }
    
        else if(mp1.size()<cap){
            mp1[key]={value, 1};
            mp2[1].push_front(key);
            auto it=mp2[1].begin();
            mp3[key]=it;
            return;
        }
        else{
            if(!mp2.empty()){
                auto it=mp2.begin();
                while(empty(it->second)) it++;
                if(it==mp2.end()) return;
                int k=it->second.back();
                it->second.pop_back();
                mp1.erase(k);
                mp3.erase(k);
                mp1[key]={value, 1};
                mp2[1].push_front(key);
                auto it2=mp2[1].begin();
                mp3[key]=it2;
                return;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */