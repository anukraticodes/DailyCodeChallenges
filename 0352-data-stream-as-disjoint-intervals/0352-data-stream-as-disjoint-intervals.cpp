class SummaryRanges {
public:
    map<int, int> mp;

    SummaryRanges() {}

    void addNum(int value) {
    auto it = mp.lower_bound(value);

    // Case 1: already exists
    if (it != mp.end() && it->first == value) return;

    int start = value, end = value;

    // Check previous interval
    if (it != mp.begin()) {
        auto prev = it;
        --prev;

        // already covered
        if (prev->second >= value) return;

        // merge with previous
        if (prev->second == value - 1) {
            start = prev->first;
            mp.erase(prev);
        }
    }

    // Check next interval
    if (it != mp.end() && it->first == value + 1) {
        end = it->second;
        mp.erase(it);
    }

    // Insert merged/new interval
    mp[start] = end;

    }


    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto it : mp) {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */