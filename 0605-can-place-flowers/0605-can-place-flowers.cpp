class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int l=n;
        int i;
        if(f.size()==1){
            if(f[0]==0 && n==1) return 1;
            if(f[0]==1 && n==1) return 0;
            if(n==0) return 1;
        }
        if(f[0]==0 && f[1]==0) {f[i]=1; l--;}
        
        for(i=1; i<f.size()-1; i++){
            if(f[i]==0 && f[i+1]==0 && f[i-1]==0){
                f[i]=1;
                l--;
            }
        }
        
        if(f[f.size()-2]==0 && f[f.size()-1]==0) l--;
        // for(; i<f.size(); i=i+2){
        //    if(f[i]==0) l--;
        // }
        return l<=0;
    }
};