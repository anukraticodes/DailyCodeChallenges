class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        if(position.size()<m) return -1;
        sort(position.begin(), position.end());
        int low=1;
        int high=1e9;
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            if(helper(position, mid, m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }

    bool helper(vector<int>& position, int dist, int balls){
        int cnt=1;
        int last=position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-last>=dist){
                cnt++;
                last=position[i];
            }
            if(cnt>=balls) return true;
        }
        return false;
    }
};