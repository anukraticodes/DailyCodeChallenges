class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        vector<bool> v;
        int n=d.size();
        int x=0;
        for(int i=0; i<n; i++){
           x=x^d[i];
        }
        return x==0;
    }
};