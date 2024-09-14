class Solution {
public:
    vector<int> parent, size;

    void dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findP(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findP(parent[node]);
    }

    void unite(int u, int v) {
        int pu = findP(u);
        int pv = findP(v);
        if (pu != pv) {
            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
    }

    int largestIsland(vector<vector<int>>& g) {
        int n = g.size();
        dsu(n * n);
        int mx = 0;
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (g[row][col] == 0) continue;  
                for (auto dir : dirs) {
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && g[nrow][ncol] == 1) {
                        int newnode = row * n + col;
                        int adjnode = nrow * n + ncol;
                        unite(newnode, adjnode);
                    }
                }
            }
        }

        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (g[row][col] == 1) continue; 
                set<int> unique_parents;
                for (auto dir : dirs) {
                    int newr = row + dir[0];
                    int newc = col + dir[1];
                    if (newr >= 0 && newc >= 0 && newr < n && newc < n && g[newr][newc] == 1) {
                        unique_parents.insert(findP(newr * n + newc));
                    }
                }
                int total_size = 1; 
                for (auto parent : unique_parents) {
                    total_size += size[parent];
                }
                mx = max(mx, total_size);
            }
        }

        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (g[row][col] == 1) {
                    mx = max(mx, size[findP(row * n + col)]);
                }
            }
        }

        return mx;
    }
};
