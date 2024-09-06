class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int d) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }

        for(int i=0; i<e.size(); i++){
            dist[e[i][0]][e[i][1]]=e[i][2];
            dist[e[i][1]][e[i][0]]=e[i][2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int min_reachable=n;
        int result=-1;

        for(int i=0; i<n; i++){
            int cities=0;

            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j]<=d) cities++;
            }
            if(cities<min_reachable|| (cities==min_reachable && i>result)){
            min_reachable=cities;
            result=i;
        }
        }
        
        return result;
    }
};