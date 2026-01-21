class Solution {
public:

    bool possible(vector<int>& w, int days, int mid){
        int cnt=1, curr=0;
        for(int r=0; r<w.size(); r++){
            curr+=w[r];
            if(curr>mid){
                cnt++;
                curr=0;
                r--;
            }
            if(cnt>days) return 0;
        }
        return 1;
    }

    int shipWithinDays(vector<int>& w, int days) {
        int l=*max_element(w.begin(), w.end()), r=accumulate(w.begin(), w.end(), 0);
        while(l<r){
            int mid=(l+r)/2;
            if(possible(w, days, mid))r=mid;
            else l=mid+1;
        }
        return l;
    }
};