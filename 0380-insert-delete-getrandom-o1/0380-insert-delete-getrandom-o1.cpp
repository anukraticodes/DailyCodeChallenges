class RandomizedSet {
public:
    unordered_map<int, int> st;
    vector<int> v;
    RandomizedSet() {}

    bool insert(int val) {
        if (st.count(val))
            return 0;
        st[val] = v.size();
        v.push_back(val);
        return 1;
    }

    bool remove(int val) {
        if (st.count(val)) {
            int idx = st[val];
            int last = v.back();

            v[idx] = last;
            st[last] = idx;

            v.pop_back();
            st.erase(val);
            return 1;
        }
        return 0;
    }

    int getRandom() {
        mt19937 gen(random_device{}());  // seed
uniform_int_distribution<> dist(0, v.size()-1);

 int x = dist(gen);
 return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */