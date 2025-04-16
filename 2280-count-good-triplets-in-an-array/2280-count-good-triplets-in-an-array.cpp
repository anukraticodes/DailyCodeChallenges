using ll = long long;
class Fenwick {
public:
    vector<ll> tree;
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }
    
    void update(int k, int x) {
        k++;
        while(k < tree.size()) {
            tree[k] += x;
            k += k & -k;
        }
    }
    
    ll query(int k) {
        ll total = 0;
        k++;
        while(k > 0) {
            total += tree[k];
            k -= k & -k;
        }
        return total;
    }
};

class Solution {
public:
    ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size(), total = 0;
        vector<int> mpp(n, 0);
        for(int i = 0; i < n; i++) mpp[nums1[i]] = i;
        
        Fenwick fw(n);
        
        for(int i : nums2) {
            int idx = mpp[i];
            ll left = fw.query(idx);
            ll sum = fw.query(n - 1);
            ll right = (n - 1 - idx) - (sum - left);
            total += left * right;
            fw.update(idx, 1);
        }
        return total;
    }
};