class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        for(int i=0; i<n; i++){
            if(board[i][0]=='O') dfs(board, i, 0);
            if(board[i][m-1]=='O') dfs(board, i, m-1);
        }

        for(int j=0; j<m; j++){
            if(board[0][j]=='O') dfs(board, 0, j);
            if(board[n-1][j]=='O') dfs(board, n-1, j);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
    vector<int> drc={-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>>& board, int i, int j){
        int n=board.size(), m=board[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;
        board[i][j]='#';
        for(int k=0; k<4; k++){
            int nx=i+drc[k], ny=j+drc[k+1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O'){
               dfs(board, nx, ny);
            }
        }
    }
};