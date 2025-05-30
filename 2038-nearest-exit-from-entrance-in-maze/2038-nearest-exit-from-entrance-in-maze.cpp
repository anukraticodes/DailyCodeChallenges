class Solution {
public:

    int ans=INT_MAX;

    bool isEdge(int r, int c, int n, int m){
        return (r==0)||(r==n-1)||(c==0)||(c==m-1);
    }

    void helper(vector<vector<char>>& maze, int r, int c, int n, int m){
        queue<tuple<int, int, int>> q;
        q.push({r, c, 0});
        vector<int> dir={-1, 0, 1, 0, -1};
        while(!q.empty()){
            auto [i, j, steps]=q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nr=i+dir[k], nc=j+dir[k+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m&& maze[nr][nc]=='.'){
                    if(isEdge(nr, nc, n, m) && !(nr == r && nc == c)){
                        maze[nr][nc]='+';
                        ans=min(ans, steps+1);
                    }
                    else{
                        maze[nr][nc]='+';
                        q.push({nr, nc, steps+1});
                    }
                }
            }

        }
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        helper(maze, e[0], e[1], maze.size(), maze[0].size());
        return ans==INT_MAX?-1:ans;
    }
};