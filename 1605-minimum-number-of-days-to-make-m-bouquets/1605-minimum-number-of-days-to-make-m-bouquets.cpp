class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         if ((long long)bloomDay.size() < (long long)m * k) return -1;
        long long low=1, high=1e9;
        while(low<high){
            long long mid=low + (high-low)/2;

            if(helper(bloomDay, m, k, mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }


    bool helper(vector<int>& bloomDay, int m, int k, long long day){
        long long total=0;
        for(long long i=0; i<bloomDay.size(); i++){
            long long cnt=0;
            while(i<bloomDay.size()&& cnt<k && bloomDay[i]<=day){
                cnt++;
                i++;
            }

            if(cnt==k){
                total++;
                i--;
            }

            if(total>=m) return true;
        }
        return false;
    }
};