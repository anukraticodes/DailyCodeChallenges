class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int cnt=INT_MIN;
        unordered_set<int> set;
        int l=0;
        
        for(int r=0; r<s.size(); r++){
            if(set.find(s[r])!=set.end()){
                while(l<r && set.find(s[r])!=set.end()){
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            cnt=max(cnt, r-l+1);
        }
        return cnt;
    }
};