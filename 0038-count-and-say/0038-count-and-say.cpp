class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
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

    // string rle(string& s){
    //     int cnt=0; char ch=s[0];
    //     string s1="";
    //     for(auto c:s){
    //        if(c==ch) cnt++;
    //        else {s1+=to_string(cnt);
    //        s1+=ch;
    //        ch=c;
    //        cnt=1;
    //        }
    //     }
    //     s1+=to_string(cnt);
    //     s1+=ch;
    //     return s1;
    // }
};