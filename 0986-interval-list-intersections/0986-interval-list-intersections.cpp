class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int i=0, j=0;
        vector<vector<int>> ans;

        while(i<fl.size() && j<sl.size()){
            int a=max(fl[i][0], sl[j][0]), b=min(fl[i][1], sl[j][1]);

            if(a<=b) ans.push_back({a,b});

            if(fl[i][1]<sl[j][1]) i++;
            else j++;
        }
        return ans;
    }
};