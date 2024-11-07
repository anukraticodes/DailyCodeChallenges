class Solution {
public:
    int largestCombination(vector<int>& c) {
        int n=c.size();
        int cnt=INT_MIN;
        for(int i=0; i<32; i++){
            int ans=0;
            for(auto ca:c){
                if(ca&(1<<i)) ans++;
            }
            cnt=max(ans, cnt);
        }
        return cnt;

    }
};