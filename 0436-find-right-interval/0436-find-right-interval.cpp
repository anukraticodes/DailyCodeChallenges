class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       vector<vector<int>> temp=intervals;
        if(intervals.size()<1) return {-1};
        sort(temp.begin(), temp.end());
        vector<int> ans;
        int outlier=temp[0][0]-1;
        for(int i=0; i<intervals.size(); i++){
            
            int t=helper(temp, intervals[i][1], outlier);
            if(t==outlier){ans.push_back(-1); continue;}
            ans.push_back(ind(t, intervals));
        }
        return ans;
    }

    int helper(vector<vector<int>>& intervals, int target, int outlier){
        int l=0, r=intervals.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(intervals[mid][0]<target) l=mid+1;
            else if(intervals[mid][0]>=target) r=mid-1;
        }
        if(l==intervals.size()) return outlier;
        return intervals[l][0];
    }

    int ind(int t, vector<vector<int>>& inte){
        for(int i=0; i<inte.size(); i++) if(inte[i][0]==t) return i;
        return -1;
    }
};