class Cell{
    public:
    int row, col, value;
    Cell(int r, int c, int v): row(r), col(c), value(v){}
};

class Query{
    public:
    int index, value;
    Query(int i, int v): index(i), value(v){}
};

bool operator<(const Query& a, const Query& b) {return a.value< b.value;}

bool operator<(const Cell& a, const Cell& b) {return a.value<b.value;}

class UnionFind{
    public:
    vector<int> parent, size;

    UnionFind(int n): parent(vector<int>(n, -1)), size(vector<int>(n, 1)){}

    int find(int node){
        if(parent[node]<0) return node;
        return parent[node]=find(parent[node]);
    }

    bool union_nodes(int u, int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return 0;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return 1;
    }

    int getSize(int node) {return size[find(node)];}
};

const vector<int> ROW_DIRECTIONS = {0, 0, 1, -1};
const vector<int> COL_DIRECTIONS = {1, -1, 0, 0};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        int totalCells = rowCount * colCount;

        // Store queries with their original indices to maintain result order
        vector<Query> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back(Query(i, queries[i]));
        }
        // Sort queries in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());

        // Store all grid cells and sort them by value
        vector<Cell> sortedCells;
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                sortedCells.push_back(Cell(row, col, grid[row][col]));
            }
        }
        // Sort cells by value
        sort(sortedCells.begin(), sortedCells.end());

        // Union-Find to track connected components
        UnionFind uf = UnionFind(totalCells);
        vector<int> result(queries.size());
        int cellIndex = 0;

        // Process queries in sorted order
        for (Query query : sortedQueries) {
            // Process cells whose values are smaller than the current query
            // value
            while (cellIndex < totalCells &&
                   sortedCells[cellIndex].value < query.value) {
                int row = sortedCells[cellIndex].row;
                int col = sortedCells[cellIndex].col;
                // Convert 2D position to 1D index
                int cellId = row * colCount + col;

                // Merge the current cell with its adjacent cells that have
                // already been processed
                for (int direction = 0; direction < 4; direction++) {
                    int newRow = row + ROW_DIRECTIONS[direction];
                    int newCol = col + COL_DIRECTIONS[direction];

                    // Check if the new cell is within bounds and its value is
                    // smaller than the query value
                    if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                        newCol < colCount &&
                        grid[newRow][newCol] < query.value) {
                        uf.union_nodes(cellId, newRow * colCount + newCol);
                    }
                }
                cellIndex++;
            }
            // Get the size of the connected component containing the top-left
            // cell (0,0)
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
        }
        return result;
    }
};