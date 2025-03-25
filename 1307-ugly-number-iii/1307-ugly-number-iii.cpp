class Solution {
public:
long long lcm(long long x, long long y) {
        return (x / __gcd(x, y)) * (long long)y;  // Explicitly cast to long long
    }

    long long helper(long long x, long long a, long long b, long long c) {
        return (x / a) + (x / b) + (x / c)
            - (x / lcm(a, b)) - (x / lcm(b, c)) - (x / lcm(a, c))
            + (x / lcm(lcm(a, b), c));
    }


    int nthUglyNumber(int n, int a, int b, int c) {
        int l = min({a, b, c}), r = (int) 2e9;
        int ans = -1;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(helper(mid, a, b, c)<n) l=mid+1;
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};