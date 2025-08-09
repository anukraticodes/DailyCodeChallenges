class Solution {
public:
    int distanceTraveled(int mainTank, int add) {
        int cnt=0;
        while(mainTank){
          if(mainTank<5) return cnt+(mainTank*10);
          if(add!=0){
            mainTank-=4;
            add--;
            cnt+=50;
          }
          else{
            mainTank-=5;
            cnt+=50;
          }
        }
        return cnt;
    }
};