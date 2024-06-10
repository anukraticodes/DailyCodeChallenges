class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt=0;
        vector<int> v=heights;
        for(int i=0; i<heights.size()-1; i++){
            for(int j=i+1; j<heights.size(); j++){
                if(heights[i]>heights[j]){
                        int temp=heights[i];
                        heights[i]=heights[j];
                        heights[j]=temp;
                }
            }
        }
        for(int i=0; i<heights.size(); i++){
            if(v[i]!=heights[i])
            cnt++;
        }

        return cnt;
    }
};