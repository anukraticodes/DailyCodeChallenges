class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return helper(0, s, seen);
    }

    int helper(int start, string& s, unordered_set<string>& seen){
        if(start==s.size()) return 0;
        int cnt=0;
        for(int i=start+1; i<=s.size(); i++){
            string sub=s.substr(start, i-start);
            if(seen.find(sub)==seen.end()){
                seen.insert(sub);
                cnt=max(cnt, 1+helper(i, s, seen));
                seen.erase(sub);
            }
        }
        return cnt;
    }
};