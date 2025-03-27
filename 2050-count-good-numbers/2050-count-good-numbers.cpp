class Solution {
public:
int mod=1e9+7;
long long pow(long long b, long long e, long long ans){
    if(e==0) return ans;
    if(e&1) return pow(b, e-1, (ans*b)%mod);
    else return pow((b*b)%mod, e/2, ans);
}
    int countGoodNumbers(long long n) {
       long long temp=pow(20, n/2, 1);
       return n&1 ?(temp*5)%mod :temp;
    }
};