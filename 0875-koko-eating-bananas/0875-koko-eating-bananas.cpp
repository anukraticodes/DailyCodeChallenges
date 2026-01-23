class Solution {
public:

    bool helper(vector<int>& piles, int speed, int H){
        int total=0;
        for(int pile:piles){
           total+=(pile+speed-1)/speed;
           if(total>H) return 0;
        }
        return total<=H;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(helper(piles, mid, h)){ans=mid; r=mid-1;}
            else l=mid+1;
        }
        return ans;
    }
};