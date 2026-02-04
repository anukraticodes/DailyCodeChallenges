class Solution {
public:

struct SegTree{
    vector<int> tree;
    SegTree(int n){
       tree.resize(4*n);
    }

    void update(int val, int l, int r, int i){
        if(l==r){
            tree[i]+=1;
            return;
        }
        int mid=(l+r)/2;
        if(val<=mid){
            update(val, l, mid, 2*i);
        }
        else update(val, mid+1, r, 2*i+1);
        tree[i]=tree[2*i]+tree[2*i+1];
    }

    int query(int ql, int qr, int l, int r, int i){
          if (r < ql || l > qr) return 0;
         if (ql <= l && r <= qr) return tree[i];
         int mid=(l+r)/2;
         auto left=query(ql, qr, l, mid, 2*i);

         auto right=query(ql, qr, mid+1, r, 2*i+1);

         return left+right;
    }
    
};
    vector<int> countSmaller(vector<int>& nums) {
        int sm=*min_element(nums.begin(), nums.end());
        int bg=*max_element(nums.begin(), nums.end());
        int n=bg-sm+1;
        SegTree st(n);
        vector<int> ans(nums.size());
        for(int i=nums.size()-1; i>=0; i--){
            int idx = nums[i] - sm;

            ans[i]=nums[i]-sm>0?st.query(0, idx - 1, 0, n - 1, 1)
:0;
            st.update(idx, 0, n-1, 1);
        }
        return ans;
    }
};