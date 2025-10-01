class Solution {
public:
    int numWaterBottles(int numB, int numEx) {
        int cnt=0;
        while(numB>=numEx){
            cnt+=numEx;
            numB-=numEx;
            numB++;    
        }
        cnt+=numB;
        return cnt;
    }
};