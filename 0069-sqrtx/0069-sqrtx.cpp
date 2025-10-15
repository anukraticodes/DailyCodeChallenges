class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=x;
        while(l<=r){
            
            long long mid=l+(r-l)/2;
            if((mid*mid)<=(long long)x) l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};