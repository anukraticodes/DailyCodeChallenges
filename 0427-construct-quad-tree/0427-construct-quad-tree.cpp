/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int isleaf(vector<vector<int>>& grid){
        int n=grid.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=accumulate(grid[i].begin(), grid[i].end(),0);
        }
        if(sum==0) return 0;
        if(sum==(n*n)) return 1;
        return -1;
    }
    vector<vector<int>> make(vector<vector<int>>& grid, int x, int y, int x2, int y2){
        int n=grid.size();
        vector<vector<int>> ans(n/2, vector<int>(n/2));
        int k1=0, k2=0;
        for(int i=x; i<=x2; i++){
            k2=0;
            for(int j=y; j<=y2; j++){
                ans[k1][k2]=grid[i][j];
                k2++;
            }
            k1++;
        }
        return ans;
    }

    Node* construct(vector<vector<int>>& grid) {
        Node* root;
        int ans=isleaf(grid);
        if(ans!=-1){
          return root=new Node(ans, 1, nullptr, nullptr, nullptr, nullptr);
        }
        int n=grid.size();
        vector<vector<int>> tl=make(grid, 0,0,(n/2)-1,(n/2)-1);
        vector<vector<int>> tr=make(grid, 0,(n/2),(n/2)-1,n-1);
        vector<vector<int>> bl=make(grid, n/2,0,n-1,(n/2)-1);
        vector<vector<int>> br=make(grid, n/2,n/2,n-1,n-1);
        Node* topleft=construct(tl);
        Node* topright=construct(tr);
        Node* bottomleft=construct(bl);
        Node* bottomright=construct(br);
        root=new Node(0,0, topleft, topright, bottomleft, bottomright);
        return root;
    }
};