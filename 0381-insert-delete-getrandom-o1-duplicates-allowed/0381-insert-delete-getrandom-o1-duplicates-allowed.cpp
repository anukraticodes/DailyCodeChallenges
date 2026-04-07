class RandomizedCollection {
public:
unordered_map<int, unordered_set<int>> mp;
vector<int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag=1;
        if(mp.count(val)) flag=0;
        mp[val].insert(v.size());
        v.push_back(val);
        return flag;
    }
    
    bool remove(int val) {
    if(!mp.count(val) || mp[val].empty()) return false;

    int it = *mp[val].begin();
    mp[val].erase(it);

    int last = v.back();

    if(it != v.size() - 1) {
        v[it] = last;
        mp[last].erase(v.size() - 1);
        mp[last].insert(it);
    }

    v.pop_back();

    if(mp[val].empty()) mp.erase(val);

    return true;
}
    
    int getRandom() {
        int x=rand()%v.size();
        return v[x];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */