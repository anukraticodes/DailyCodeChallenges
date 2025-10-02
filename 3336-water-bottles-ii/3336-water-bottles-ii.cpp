class Solution {
public:
    int maxBottlesDrunk(int numB, int numE) {
        int cnt=numB;
        int numempty=numB;
        numB=0;
        while(numempty>=numE){
            numempty-=numE;
            numB=1;
            numE++;
            cnt+=1;
            numempty+=1;
        }
        return cnt;
    }
};