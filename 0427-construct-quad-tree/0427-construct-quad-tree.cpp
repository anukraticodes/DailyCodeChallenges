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

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
    int isleaf(vector<vector<int>>& grid, int x, int y, int x2, int y2) {
        int sum = 0;
        for (int i = x; i <= x2; i++) {
            for (int j = y; j <= y2; j++) {
                sum += grid[i][j];
            }
        }

        int total = (x2 - x + 1) * (y2 - y + 1);
        if (sum == 0)
            return 0;
        if (sum == total)
            return 1;
        return -1;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return construct2(grid, 0, 0, n - 1, n - 1);
    }

    Node* construct2(vector<vector<int>>& grid, int x, int y, int x2, int y2) {
        Node* root;
        int ans = isleaf(grid, x, y, x2, y2);
        if (ans != -1) {
            return root = new Node(ans, 1, nullptr, nullptr, nullptr, nullptr);
        }
        int midX = (x + x2) / 2;
    int midY = (y + y2) / 2;

    Node* topleft = construct2(grid, x, y, midX, midY);
    Node* topright = construct2(grid, x, midY + 1, midX, y2);
    Node* bottomleft = construct2(grid, midX + 1, y, x2, midY);
    Node* bottomright = construct2(grid, midX + 1, midY + 1, x2, y2);
        root = new Node(0, 0, topleft, topright, bottomleft, bottomright);
        return root;
    }
};