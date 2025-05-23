class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        function<bool(int, int, int)> backtrack=[&](int i, int j, int k){
            if(k==word.length()) return 1;
            if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[k]) return 0;
            char temp=board[i][j];
            board[i][j]='\0';
            if(backtrack(i+1, j, k+1)||backtrack(i-1, j, k+1)||backtrack(i, j+1, k+1)||backtrack(i, j-1, k+1)) return 1;
            board[i][j]=temp;
            return 0;
        };
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0])
                if(backtrack(i, j, 0)) return 1;
            }
        }
        return 0;
    }
};