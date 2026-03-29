class LFUCache {
public:
    unordered_map<int, pair<int, int>> mp1;
    unordered_map<int, list<int>> mp2;
    unordered_map<int, list<int>::iterator> mp3;
    int cap, minf;

    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
    }
    
    int get(int key) {
        if (!mp1.count(key)) return -1;

        auto [val, freq] = mp1[key];

        // remove from old freq
        mp2[freq].erase(mp3[key]);
        if (mp2[freq].empty()) {
            mp2.erase(freq);
            if (minf == freq) minf++;
        }

        // add to new freq
        mp2[freq + 1].push_front(key);
        mp3[key] = mp2[freq + 1].begin();
        mp1[key].second++;

        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        if (mp1.count(key)) {
            mp1[key].first = value;
            get(key); // reuse logic
            return;
        }

        if (mp1.size() == cap) {
            int k = mp2[minf].back();
            mp2[minf].pop_back();

            if (mp2[minf].empty()) {
                mp2.erase(minf);
            }

            mp1.erase(k);
            mp3.erase(k);
        }

        mp1[key] = {value, 1};
        mp2[1].push_front(key);
        mp3[key] = mp2[1].begin();
        minf = 1;
    }
};