class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int l=0,r=0,sum=0;
        for(int i=0; i<k; i++){
            l+=c[i];
        }
        sum=l;
        for(int i=k-1,j=c.size()-1; i>=0; i--, j--){
            l-=c[i];
            r+=c[j];
            sum=max(sum,l+r);
        }
        return sum;
    }
};