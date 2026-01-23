class Solution {
public:

    bool possible(int mid, vector<int>& p, int m){
        int curr=1;
        int l=0;
        for(int r=1; r<p.size(); r++){
            // curr+=p[r];
            if(p[r]-p[l]>=mid){
                l=r;
                if(++curr >= m) return 1;
            }
        }
        return 0;
    }

    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int l=0, r=p[p.size()-1]-p[0], ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(possible(mid, p, m)) {ans=mid;l=mid+1;}
            else r=mid-1;
        }
        return ans;
    }
};