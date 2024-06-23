class Solution {
public:
    int trap(vector<int>& height) {
        int cnt=0;
       
        vector<int> prefix(height.size());
         int num=height[0];
        for(int i=0; i<height.size(); i++){
           num=max(num, height[i]);
           prefix[i]=num;
        }

         vector<int> suffix(height.size());
         num=height[height.size()-1];
        for(int i=height.size()-1; i>=0; i--){
           num=max(num, height[i]);
           suffix[i]=num;
        }

        for(int i=1; i<height.size()-1; i++){
            
            int x=(min(prefix[i], suffix[i])-height[i]);
            if(x>0) cnt+=x;
        }
        return cnt;
    }
};