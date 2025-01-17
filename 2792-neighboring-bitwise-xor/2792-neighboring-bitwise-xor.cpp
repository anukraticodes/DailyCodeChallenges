class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        vector<bool> v;
        int n=d.size();
        if(n==1 && d[0]==0) return true;
        if(n==1 && d[0]==1) return false;
        if(d[0]==1) {
            v.push_back(0); v.push_back(1); }
            else{
                v.push_back(0); v.push_back(0);
            }
        for(int i=1; i<d.size(); i++){
           if(d[i]==1){
             if(v[i]==0) v.push_back(1);
             else v.push_back(0);
           }
           else{
            if(v[i]==0) v.push_back(0);
             else v.push_back(1);
           }
        }
        return (d[n-1]==0 && v[n-1]==v[0])||(d[n-1]==1 && v[n-1]!=v[0]); 
    }
};