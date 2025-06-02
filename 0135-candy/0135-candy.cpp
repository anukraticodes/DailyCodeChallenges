class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> left(r.size(), 1), right(r.size(), 1);

        for(int i=1; i<r.size(); i++){
            if(r[i]>r[i-1]) left[i]=1+left[i-1];
        }
        for(int i=r.size()-2; i>=0; i--){
            if(r[i]>r[i+1]) right[i]=1+right[i+1];
        }
        int sum=0;
        for(int i=0; i<r.size(); i++) sum+=max(left[i], right[i]);
        return sum;
    }
};