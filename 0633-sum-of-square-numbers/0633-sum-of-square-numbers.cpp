class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        set<int> mp;
        for(long long i=0; i*i<=c; i++){
            mp.insert(i*i);
        }
        for(long long i=0; i*i<=c; i++){
            long long num=c-i*i;
            if(mp.find(num)!=mp.end())
            return true;
        }
        return false;
    }
};