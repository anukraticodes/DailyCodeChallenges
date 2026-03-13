class CountIntervals {
public:
// int ret=0;
map<int,int> mp;
    long long total = 0;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it=mp.lower_bound(left);
         if(it != mp.begin()){
            it--;
        }

        while(it != mp.end() && it->first <= right){
            if(it->second < left){
                it++;
                continue;
            }

            left = min(left, it->first);
            right = max(right, it->second);

            total -= (it->second - it->first + 1);
            it = mp.erase(it);
        }

        mp[left] = right;
        total += (right - left + 1);
    }
    
    int count() {
        return total;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */