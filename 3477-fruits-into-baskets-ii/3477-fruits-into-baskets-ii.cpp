class Solution {
public:

struct SegTree{
    vector<int> tree;
    SegTree(vector<int> nums){
        int n=nums.size();
        tree.resize(4*n, 0);
        build(0,0,n-1,nums);
    }

    void build(int ind, int l, int r, vector<int>& nums){
        if(l==r){
            tree[ind]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*ind+1, l, mid, nums);
        build(2*ind+2, mid+1, r, nums);
        tree[ind]=max(tree[2*ind+1], tree[2*ind+2]);
    }

    void update(int i, int l, int r, int ind, int val){
        if(l==r){
            tree[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(mid>=ind) update(2*i+1, l, mid, ind, val);
        else update(2*i+2, mid+1, r, ind, val);
        tree[i]=max(tree[2*i+1], tree[2*i+2]);
    }

    int helper(int i, int l, int r, int val){
        if(tree[i]<val) return -1;
        if(l==r) return l;

        int mid=(l+r)/2;
        if(tree[2*i+1]>=val) return helper(2*i+1, l, mid, val);
        return helper(2*i+2, mid+1, r, val);
    }
};
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0;
        SegTree* st=new SegTree(baskets);
        for(int i=0; i<n; i++){
            int val=st->helper(0,0,n-1,fruits[i]);
            if(val!=-1) st->update(0,0,n-1,val,0);
            else ans++;
        }
        return ans;    
    }
};