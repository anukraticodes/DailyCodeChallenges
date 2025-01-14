class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26);
        int cnt=0;
        int l=0, r=0,t=k;
        int ans=INT_MIN;
        for(int i=0; i<26; i++){
            l=0; 
            cnt=0;
            for(r=0; r<s.size()&& l<s.size(); r++){
                if(s[r]!=i+'A') cnt++;
                while(cnt>k){
                   if(s[l]!=i+'A') cnt--;
                   l++;
                }
                ans=max(ans,r-l+1);
                
            }  
            
            
        }
        return ans;
    }
};