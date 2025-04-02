class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int start=0, end=0;

        for(int i=0; i<s.size(); i++){
            int odd=helper(i, i, s);
            int even=helper(i, i+1, s);
            int maxl=max(odd, even);

            if(maxl>end-start){
                start=i-(maxl-1)/2;
                end=i+maxl/2;
            }
        }
        return s.substr(start, end-start+1);
    }

    int helper(int i, int j, string s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
};