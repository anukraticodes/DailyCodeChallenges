class Solution {
public:

    bool helper(string s, int k){
        vector<int> v(26, 0);
        int n=s.size();
        for(int i=0; i<k; i++) v[s[i]-'a']++;
        for(int j=k; j<n; j+=k){
            vector<int> v2(26, 0);
            for(int i=0; i<k; i++){
                v2[s[j+i]-'a']++;
            }
            if(v!=v2) return 0;
        }
        return 1;
    }


    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=1; i<n; i++){
            if(n%i==0 && helper(s, i)) return i;
        }
        return n;
    }
};