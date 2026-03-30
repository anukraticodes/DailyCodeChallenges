class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> ans;
        int i=0, j=0, n=fl.size(), m=sl.size();
        while(i<n && j<m){
            int a=fl[i][0], b=fl[i][1], c=sl[j][0], d=sl[j][1];
            if(b<c) {
                i++;
            }
            else if(d<a) j++;
            else{
                int first=max(a, c), snd=min(b,d);
                if(ans.empty()) ans.push_back({first, snd});
                else{
                    if(ans.back()[1]>=first){
                        ans.back()[1]=max(ans.back()[1], snd);
                    }
                    else{
                        ans.push_back({first, snd});
                    }
                }
                if(b<d) {i++;}
                else if(d<b) {j++;}
                else {i++, j++;}
            }
        }
        return ans;
    }
};