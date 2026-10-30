class AllOne {
public:

unordered_map<string, int> mp;
set<pair<int, string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        st.erase({mp[key], key});
        mp[key]+=1;
        st.insert({mp[key], key});
    }
    
    void dec(string key) {
        st.erase({mp[key], key});
        if(--mp[key]==0) {mp.erase(key); return;}
        st.insert({mp[key], key});
    }
    
    string getMaxKey() {
        if(!st.empty()){auto [count, key]=*(st.rbegin()); return key;}
        return "";
    }
    
    string getMinKey() {
        if(!st.empty()){auto [count, key]=*(st.begin()); return key;}
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */