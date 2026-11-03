class Solution {
public:

    int distance(int a, int b){
        return ((a)*(a)) + ((b)*(b));
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int drc=1;
        set<pair<int, int>> st;
        for(auto it:obstacles){
            int x=it[0], y=it[1];
            st.insert({x,y});
        }

        int ans=0;
        int x=0, y=0;
        for(auto it:commands){
           if(it==-1) drc=(drc+1)%4;
           else if(it == -2) drc = (drc + 3) % 4;

           else{
                for(int i=0; i<it; i++){
                    if(drc==1){
                        if(st.count({x, y+1})) break;
                        y++;
                    }
                    else if(drc==2){
                        if(st.count({x+1, y})) break;
                        x++;
                    }
                    else if(drc==3){
                        if(st.count({x, y-1})) break;
                        y--;
                    }
                    else{
                        if(st.count({x-1, y})) break;
                        x--;
                    }
                }
           }
           ans=max(ans, distance(x,y));
        }
        return ans;
    }
};