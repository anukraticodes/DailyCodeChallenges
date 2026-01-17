class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        long long ans=0;
        for(int i=0; i<bl.size(); i++){
            for(int j=i+1; j<bl.size(); j++){
                long long w=min(tr[i][0], tr[j][0])-max(bl[i][0], bl[j][0]);
                long long h=min(tr[i][1], tr[j][1])-max(bl[i][1], bl[j][1]);
                ans=max(ans, min(h,w));
            }
        }
        return (long long)ans*ans;
    }
};