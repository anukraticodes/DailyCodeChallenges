class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>l(n), r(n);
        int currmax=height[0];
        l[0]=0;
        for(int i=1; i<n; i++){
            l[i]=currmax;
            if(height[i]>currmax){
                currmax=height[i];
            }
        }
        r[n-1]=0;
        currmax=height[n-1];
        for(int i=n-1; i>=0; i--){
           r[i]=currmax;
           currmax=max(currmax, height[i]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=max(0,(min(l[i], r[i])-height[i]));
        }
        return ans;
    }
};