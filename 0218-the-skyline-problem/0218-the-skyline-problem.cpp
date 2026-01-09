class Solution {
public:

struct SegTree{
    int n;
    vector<int> tree;
    SegTree(int n){
        this->n=n;
        tree.resize(4*n, 0);
    }

    void update(int ind, int l, int r, int ql, int qr, int h){
        if(r<ql||l>qr) return;
        if(ql<=l && r<=qr){
            tree[ind]=max(tree[ind], h);
            return;
        }

        int mid=(l+r)/2;
        update(2*ind,l,mid,ql,qr,h);
        update(2*ind+1,mid+1,r,ql,qr,h);
    }

    int query(int ind, int l, int r, int pos, int carry){
        carry=max(carry,tree[ind]);
        if(l==r) return carry;

        int mid=(l+r)/2;
        if(pos<=mid) return query(2*ind, l, mid, pos, carry);
        else return query(2*ind+1, mid+1, r, pos, carry);
    }
};

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> xs;
        for(auto& b:buildings){
            xs.push_back(b[0]);
            xs.push_back(b[1]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int m=xs.size();
        SegTree st(m-1);

        for(auto& b:buildings){
            int l=lower_bound(xs.begin(), xs.end(), b[0])-xs.begin();
            int r=lower_bound(xs.begin(), xs.end(), b[1])-xs.begin()-1;
            if(l<=r) st.update(1,0,m-2,l,r,b[2]);
        }
        vector<vector<int>> ans;
        int prevHeight = 0;

        for (int i = 0; i < m - 1; i++) {
            int currHeight = st.query(1, 0, m - 2, i, 0);
            if (currHeight != prevHeight) {
                ans.push_back({xs[i], currHeight});
                prevHeight = currHeight;
            }
        }
        ans.push_back({xs.back(), 0});
        return ans;
    }
};