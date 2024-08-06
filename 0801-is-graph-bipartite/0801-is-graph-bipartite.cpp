class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1); // Initialize all nodes as uncolored (-1)
        for(int i = 0; i < graph.size(); i++) {
            if(colour[i] == -1) {
                // If the node is uncolored, start a DFS with color 0
                if(!dfs(i, 0, colour, graph)) return false;
            }
        }
        return true; // If no conflicts are found, the graph is bipartite
    }

    bool dfs(int node, int color, vector<int>& colour, vector<vector<int>>& graph) {
        colour[node] = color; // Color the current node
        for(auto it: graph[node]) {
            if(colour[it] == -1) {
                // If the adjacent node is uncolored, color it with the opposite color
                if(!dfs(it, !color, colour, graph)) return false;
            } else if(colour[it] == color) {
                // If the adjacent node has the same color, the graph is not bipartite
                return false;
            }
        }
        return true; // No conflicts found, return true
    }
};
