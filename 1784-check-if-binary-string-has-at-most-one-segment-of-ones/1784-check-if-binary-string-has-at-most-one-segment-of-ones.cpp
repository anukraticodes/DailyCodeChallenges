class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag=0;
        for(auto it:s){
            if(it=='0') flag=1;
            if(flag && it=='1') return 0;
        }
        return 1;
    }
};