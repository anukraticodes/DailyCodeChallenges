class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        int x=0, y=0;
        st.insert({x,y});
        for(auto c:path){
            if(c=='N'){
                if(st.count({x, y+1})) return 1;
                st.insert({x, ++y});
            }
            else if(c=='S'){
                if(st.count({x, y-1})) return 1;
                st.insert({x, --y});
            }
            else if(c=='E'){
                if(st.count({x+1, y})) return 1;
                st.insert({++x, y});
            }
            else{
                if(st.count({x-1, y})) return 1;
                st.insert({--x, y});
            }
        }
        return 0;
    }
};