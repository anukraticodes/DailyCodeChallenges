class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0, r=h.size()-1;
        int area=INT_MIN;
        while(l<r){
            int carea=min(h[l], h[r])*(r-l);
            area=max(area, carea);
            if(h[l]<=h[r]) l++;
            else r--; 
        }
        return area;
    }
};