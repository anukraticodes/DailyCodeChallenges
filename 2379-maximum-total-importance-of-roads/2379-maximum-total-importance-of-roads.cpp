class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> v(n,0);

        for(auto road:roads){
           v[road[0]]++;
           v[road[1]]++;
        }
        vector<int> cities(n);
        for(int i=0; i<n; i++){
            cities[i]=i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b){
            return v[a]>v[b];
        });

        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=(long long)(n-i)*v[cities[i]];
        }
        return sum;
    }

    
    
};