class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum=0;
        unordered_set<int> rows, cols;
        for(int i=queries.size()-1; i>=0; i--){
            int type=queries[i][0], ind=queries[i][1], val=queries[i][2];
            if(type==0){
                if(rows.count(ind)) continue;
                sum+=((n-cols.size())*val);
                rows.insert(ind);
            }
            else{
                if(cols.count(ind)) continue;
                sum+=((n-rows.size())*val);
                cols.insert(ind);
            }
        }
        return sum;
    }
};