class Solution {
public:
    bool checkPowersOfThree(int n) {
        int t=3;
        while(t<n){
            t*=3;
        }
        while(t>0){
            if(n>=t){
                n-=t;
            }
            t=t/3;
        }
        return n==0;
    }
};