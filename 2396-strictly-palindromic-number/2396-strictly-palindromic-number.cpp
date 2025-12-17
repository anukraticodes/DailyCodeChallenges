class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<=n-2; i++){
            int temp=n;
            string d="";
            while(temp>0){
                int rem=temp%i;
                d=to_string(rem)+d;
                temp/=i;
            }
            string rev=d;
            reverse(rev.begin(), rev.end());
            if(rev!=d) return 0;
        }
        return 1;
    }
};