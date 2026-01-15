class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0; vector<int> f(3,0);
        int total=0;
        int n=s.size();
        for(int r=0; r<s.size(); r++){
           f[s[r]-'a']++;
           while(helper(f) && l<=r){
            total+=(n-r);
            f[s[l]-'a']--;
            l++;
           }
        }
        return total;
    }

    bool helper(vector<int>& f){
        return f[0]>0 && f[1]>0 && f[2]>0;
    }
};