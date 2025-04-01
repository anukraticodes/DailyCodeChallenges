class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int freq=0;
        char ch=chars[0];
        for(auto c:chars){
            if(c==ch){
                freq++;
            }
            else{
                s+=ch;
                if(freq!=1)
                s+=to_string(freq);
                ch=c;
                freq=1;
            }
        }
                s+=ch;
                if(freq!=1)
                s+=to_string(freq);
        chars={};
        for(auto c:s){
            chars.push_back(c);
        }
        return chars.size();
    }
};