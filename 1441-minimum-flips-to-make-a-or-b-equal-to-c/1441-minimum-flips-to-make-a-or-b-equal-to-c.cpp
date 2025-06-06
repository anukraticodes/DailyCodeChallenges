class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a!=0 || b!=0 || c!=0){
            if(a&1 && !(c&1)) ans++;
            if(b&1 && !(c&1)) ans++;
            if (!(a & 1) && !(b & 1) && (c & 1)) ans++;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};