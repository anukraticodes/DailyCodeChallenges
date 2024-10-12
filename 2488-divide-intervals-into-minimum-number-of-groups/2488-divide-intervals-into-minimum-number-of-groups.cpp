class Solution {
public:

    int minGroups(vector<vector<int>>& intervals) {
      vector<int> s, e;
      for(auto interval: intervals){
        s.push_back(interval[0]);
        e.push_back(interval[1]);
      }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int cnt=0, ptr=0;

        for(int start:s){
            if(start>e[ptr]) ptr++;
            else cnt++;
        }
      
      return cnt;  
    }
};