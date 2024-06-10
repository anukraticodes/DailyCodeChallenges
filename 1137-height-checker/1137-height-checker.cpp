class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt=0;
        vector<int> v=heights;
        sort(heights.begin(), heights.end());
        for(int i=0; i<heights.size(); i++){
            if(v[i]!=heights[i])
            cnt++;
        }

        return cnt;
    }
};