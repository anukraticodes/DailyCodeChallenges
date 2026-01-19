class Solution {
public:

void reset(int& l, int& cnt, int& r){
    l=r+1;
    cnt=0;
}

    bool helper(vector<int>& bd, int m, int k, int days){
        int cnt=0;
         int done=0;
        int l=0;
        for(int r=0; r<bd.size(); r++){
           if(bd[r]>days){
            reset(l,cnt,r);
            continue;
           }
        //    cnt++;
           if(++cnt==k){
            if(++done==m) return 1;
            reset(l,cnt,r);
           }
        //    if(done==m) return 1;

        }
        return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n) return -1;
        int l=*min_element(bloomDay.begin(), bloomDay.end());
        int r=*max_element(bloomDay.begin(), bloomDay.end());
        while(l<r){
            int mid=(l+r)/2;
            if(helper(bloomDay, m, k, mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};