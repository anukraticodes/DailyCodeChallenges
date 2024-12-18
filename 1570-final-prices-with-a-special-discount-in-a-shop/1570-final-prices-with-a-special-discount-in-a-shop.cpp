class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> answer;
        int n=p.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(p[j]<=p[i]){
                    answer.push_back(p[i]-p[j]);
                    break;
                }
                else if(j==n-1) answer.push_back(p[i]);
            }
            
        }
        answer.push_back(p[n-1]);
        return answer;

    }
};