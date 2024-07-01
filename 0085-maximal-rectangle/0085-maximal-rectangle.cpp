class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> heights(cols,0);
        int maxA=0;

        for(int i=0; i<rows; i++){
           for(int j=0; j<cols; j++){
            if(matrix[i][j]=='0') heights[j]=0;
            else heights[j]+=1;
           }

           vector<int> next(cols,cols);
           vector<int> prev(cols,-1);
           stack<int>s;

           for(int j=cols-1; j>=0; j--){
            while(!s.empty()&&heights[s.top()]>=heights[j]) s.pop();
            if(!s.empty()) next[j]=s.top();
            s.push(j);
           }

           s=stack<int>();

           for(int j=0; j<cols; j++){
            while(!s.empty()&&heights[s.top()]>=heights[j])s.pop();
            if(!s.empty()) prev[j]=s.top();
            s.push(j);
           }

           for(int j=0; j<cols; j++){
            int width=next[j]-prev[j]-1;
            int area=heights[j]*width;
            maxA=max(maxA, area);
           }
        }
        return maxA;
    }
};