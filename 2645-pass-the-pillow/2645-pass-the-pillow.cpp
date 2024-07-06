class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;
        else {
            
            int x=time/(n-1);
            if(x%2==0) return time%(n-1)+1;
            else return n-(time%(n-1));
        }
    }
};