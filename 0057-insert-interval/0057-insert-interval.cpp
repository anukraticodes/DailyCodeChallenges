class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newi) {
        if (in.empty()) return {newi};
        vector<vector<int>> v;
        if(newi[1]<in[0][0]){
                v.push_back({newi[0], newi[1]});
            for(int i=0; i<in.size(); i++) v.push_back(in[i]);
            return v;    
        }
        int i=0;
        while(i<in.size()){
            
            if(in[i][1]<newi[0])
               v.push_back(in[i]);
            else if(in[i][0]>newi[1]){
                v.push_back(newi);
                for(; i<in.size(); i++) v.push_back(in[i]);
            return v; 
            }
            else {v.push_back({min(in[i][0], newi[0]), max(in[i][1], newi[1])});
                break;
            }
            i++;
        }
        if(i!=in.size()){
        int prev_end=max(in[i][1], newi[1]);
        int prev_st=min(in[i][0], newi[0]);
        for(i=i+1; i<in.size(); i++){
            if(prev_end>=in[i][0]){
                v.pop_back();
                v.push_back({min(in[i][0], prev_st), max(in[i][1], prev_end)});
            prev_end=max(in[i][1], prev_end);
            prev_st=min(in[i][0], prev_st);
            }
            else{
                v.push_back(in[i]);
            }
        }
        }
        else v.push_back(newi);
        return v;
    }
};