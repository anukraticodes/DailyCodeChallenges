class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;
        vector<int> v;
        for(int i=0; i<word.size(); i++){
            char c=word[i];
            int cnt2=0;
            while(word[i+1]==c){
               cnt2++; i++;
            } 
            v.push_back(cnt2);
        }
        for(auto it:v){          
            cnt+=(it);
        }
        return cnt;
    }
};