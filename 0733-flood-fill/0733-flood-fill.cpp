class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int colour) {
        int ol_co=image[sr][sc];
        if(ol_co==colour) return image;
        dfs(sr, sc, image, colour, ol_co);
        return image;
    }

    void dfs(int sr, int sc, vector<vector<int>> &image, int colour, int ol_co){
        int m=image.size();
        int n=image[0].size();
        int drc[5]={-1, 0, 1, 0, -1};
        image[sr][sc]=colour;
        for(int i=0; i<4; i++){
            int csr=sr+drc[i];
            int csc=sc+drc[i+1];
            if(csr<m && csc<n && csr>=0 && csc>=0 && image[csr][csc]==ol_co)
            dfs(csr, csc, image, colour, ol_co);
                }

    }
};