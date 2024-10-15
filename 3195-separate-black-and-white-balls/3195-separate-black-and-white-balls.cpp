class Solution {
public:
    long long minimumSteps(string s) {
         long long cnt = 0;
        long long white=0;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='0') cnt+=white;
            else if(s[j]=='1') white++;
        }


        return cnt;
    }
};