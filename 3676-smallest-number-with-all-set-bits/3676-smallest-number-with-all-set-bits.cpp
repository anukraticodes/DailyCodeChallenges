class Solution {
public:
    int smallestNumber(int n) {
        int ans=1;
        while(true){
            if(ans-1>=n) return ans-1;
            ans*=2;
        }
        return 1;
    }
};