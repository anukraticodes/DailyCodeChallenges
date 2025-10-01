class Solution {
public:
    int numWaterBottles(int numB, int numEx) {
        int cnt=numB;
        while(numB>=numEx){
            
            cnt+=numB/numEx;
            numB=(numB/numEx)+(numB%numEx);
   
            
        }
        return cnt;
    }
};