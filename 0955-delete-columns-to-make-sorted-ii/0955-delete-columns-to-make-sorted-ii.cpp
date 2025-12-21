class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> res(strs.size()-1, 0);
        int del=0;
        // int unr=strs.size()-1;
        for(int col=0; col<strs[0].size(); col++){
            bool bad=0;
            for(int i=0; i<strs.size()-1; i++){
                if(!res[i] && strs[i][col]>strs[i+1][col]){
                    bad=1;
                    break;
                }
            }
            if(bad){
               del++;
               continue;
            }
            for(int i=0; i<strs.size()-1; i++){
                if(!res[i] && strs[i][col]<strs[i+1][col]){
                    res[i]=1;
                }
            }
        }
        return del;
    }
};