class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [&](const auto a, const auto b){
           return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        });
        int ans=0;
        for(int i=0; i<p.size(); i++){
            int b=p[i][1], last=-1;
            for(int j=i+1; j<p.size(); j++){
               int a=p[j][1];
               if(a<=b && a>last){
                last=a;
                ans++;
               }

            }
        }
        return ans;
    }
};