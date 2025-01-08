class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(isreal(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }

  bool isreal(string s1, string s2)
{
    int n=s1.size();
    int n1=s2.size();
    if(n1<n) return 0;
    string str1="", str2="";
    for(int i=0; i<n;i++){
    str1+=s2[i];
    str2+=s2[n1-1-i];
    }
    reverse(str2.begin(), str2.end());
    return s1==str1 && s1==str2;
}};