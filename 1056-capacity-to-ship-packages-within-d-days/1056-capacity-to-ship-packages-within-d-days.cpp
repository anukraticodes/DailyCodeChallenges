class Solution {
public:
    bool helper(vector<int>& w, int days, int mid){
        int total=1, cnt=0;      
        for(int i=0; i<w.size(); i++){
            if(cnt+w[i]>mid){
                total++;cnt=0;
                if(total>days) return 0;
            }
            cnt+=w[i];
        }
        return total<=days;
    }

    int shipWithinDays(vector<int>& w, int days) {
        int l=*max_element(w.begin(), w.end());
        int r=accumulate(w.begin(), w.end(), 0);
        while(l<r){
            int mid=l+(r-l)/2;
            if(helper(w, days, mid))r=mid;
            else l=mid+1;
        }
        return l;
    }
};
