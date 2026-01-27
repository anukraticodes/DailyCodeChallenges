class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
       long long val=n;
        if(val<0) val=-1*val;
        while(val>0)
        {
            if(val&1){
                ans=ans*x;
                val--;
            }
            else{
                x=x*x;
                val/=2;

            }
    }
    if(n<0) return (double)1.0/(double) ans;
    return ans;
    }
};