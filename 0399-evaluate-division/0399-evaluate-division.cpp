class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int>idx ; 
        int n = 0 ; 
        for(int i=0 ; i<equations.size() ; i++){
            string u = equations[i][0] ; 
            string v = equations[i][1] ;
            if(idx.find(u) == idx.end()){
                idx[u] = n++;
            } 
            if(idx.find(v) == idx.end()){
                idx[v] = n++ ; 
            }
        }// this loop gives each string unique index
        vector<vector<double>> mat(n , vector<double>(n,-1));  
        for(int i=0 ; i<equations.size() ; i++){
                string u = equations[i][0] ; 
                string v = equations[i][1] ;
                mat[idx[u]][idx[v]] = values[i] ; 
                mat[idx[v]][idx[u]] = 1.0/values[i] ; 
        }// this loop initializes known values in matrix
        for(int i=0 ; i<n ; i++){
            mat[i][i] = 1 ; 
        }
        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    if(mat[i][j] == -1){
                        if(mat[i][k]>0 and mat[k][j]>0){
                            mat[i][j] = mat[i][k]*mat[k][j] ; 
                        }
                    }
                }
            }
        }// finds route from i->j via k
        vector<double> ans ; 
        for(int i=0 ; i<queries.size() ; i++){
            string u = queries[i][0] ;
            string v = queries[i][1] ; 
            if(idx.find(u) == idx.end()){
                ans.push_back(-1) ; 
            }
            else if(idx.find(v) == idx.end()){
                ans.push_back(-1) ; 
            }
            else{
                ans.push_back(mat[idx[u]][idx[v]]) ; 
            }
        }//populates ans array
        return ans ; 
    }
};