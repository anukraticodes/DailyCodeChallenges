class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s="1";
        string ans;
        for(int i=0; i<n-1; i++){
           ans=rle(s);
           s=ans;
        }
        return ans;
        
    }

    string rle(string& s){
        int cnt=0; char ch=s[0];
        string s1="";
        for(auto c:s){
           if(c==ch) cnt++;
           else {s1+=to_string(cnt);
           s1+=ch;
           ch=c;
           cnt=1;
           }
        }
        s1+=to_string(cnt);
        s1+=ch;
        return s1;
    }
};