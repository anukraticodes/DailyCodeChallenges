class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        priority_queue<pair<double, int>> pq;
        int n=classes.size();
        double ans=0.0;
        for(int i=0; i<classes.size(); i++){
           double val;
           val=(double)(classes[i][0]+1)/(classes[i][1]+1)-(double)(classes[i][0])/(classes[i][1]);
           pq.push({val, i});
           ans+=((double)classes[i][0])/(classes[i][1]);
        }
        while(es--){
            auto [val, ind]=pq.top();
            pq.pop();
            ans+=val;
            classes[ind][0]++;
            classes[ind][1]++;
            val=(double)(classes[ind][0]+1)/(classes[ind][1]+1)-(double)(classes[ind][0])/(classes[ind][1]);
            pq.push({val, ind});
        }
        return ans/n;
    }
};