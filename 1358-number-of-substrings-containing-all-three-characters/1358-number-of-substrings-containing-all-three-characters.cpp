class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0; unordered_map<char, int> mp;
        int total=0;
        int n=s.size();
        for(int r=0; r<s.size(); r++){
           mp[s[r]]++;
           while(mp.size()==3 && l<=r){
            total+=(n-r);
            if(mp[s[l]]==1) mp.erase(s[l]);
            else mp[s[l]]--;
            l++;
           }
        }
        return total;

    }
};