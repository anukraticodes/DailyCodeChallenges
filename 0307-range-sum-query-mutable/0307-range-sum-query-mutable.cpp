class NumArray {
public:

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
        }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

        int query(int node, int l, int r, int ql, int qr) {
            if (r < ql || l > qr) return 0;
            if (ql <= l && r <= qr) return tree[node];
            int mid = (l + r) / 2;
            return query(2 * node, l, mid, ql, qr) +
                   query(2 * node + 1, mid + 1, r, ql, qr);
        }
    };
SegTree* st;

    NumArray(vector<int>& nums) {
        st = new SegTree(nums);
    }

    void update(int index, int val) {
        st->update(1, 0, st->n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return st->query(1, 0, st->n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */