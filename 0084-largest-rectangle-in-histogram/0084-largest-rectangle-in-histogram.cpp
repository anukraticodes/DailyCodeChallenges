class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for(int i=0; i<heights.size(); i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(!s.empty())left[i]=s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();
        for(int i=heights.size()-1; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(!s.empty())right[i]=s.top();
            s.push(i);
        }
        int large=INT_MIN;
        for(int i=0; i<heights.size(); i++){
           large=max(large, heights[i]*(right[i]-left[i]-1));
        }
        return large;
    }
};