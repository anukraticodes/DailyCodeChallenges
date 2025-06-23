class Solution {
public:
    vector<string> maxNumOfSubstrings(string S) {
        int n = S.size();
        vector<int> mins(26, INT_MAX);
        vector<int> maxs(26, -1);
        vector<bool> exists(26, false);
        vector<vector<int>> prefixSum(n + 1, vector<int>(26, 0));

        // Preprocessing
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            int ch = S[i] - 'a';
            prefixSum[i + 1][ch]++;
            mins[ch] = min(mins[ch], i);
            maxs[ch] = max(maxs[ch], i);
            exists[ch] = true;
        }

        // Build graph
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                for (int j = 0; j < 26; j++) {
                    int cnt = prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j];
                    if (cnt > 0) {
                        graph[i][j] = true;
                    }
                }
            }
        }

        // Kosaraju’s algorithm
        vector<int> stack;
        vector<bool> visited(26, false);
        for (int i = 0; i < 26; i++) {
            if (exists[i] && !visited[i]) {
                dfs1(i, graph, visited, stack);
            }
        }

        int batch = 0;
        vector<int> batches(26, -1);
        vector<int> degree(26, 0);
        for (int i = stack.size() - 1; i >= 0; i--) {
            int v = stack[i];
            if (batches[v] == -1) {
                dfs2(v, graph, batches, batch, degree);
                batch++;
            }
        }

        vector<string> res;
        for (int i = batch - 1; i >= 0; i--) {
            if (degree[i] == 0) {
                int minIndex = INT_MAX, maxIndex = -1;
                for (int j = 0; j < 26; j++) {
                    if (batches[j] == i) {
                        minIndex = min(minIndex, mins[j]);
                        maxIndex = max(maxIndex, maxs[j]);
                    }
                }
                res.push_back(S.substr(minIndex, maxIndex - minIndex + 1));
            }
        }

        return res;
    }

private:
    void dfs1(int v, vector<vector<bool>>& graph, vector<bool>& visited, vector<int>& stack) {
        visited[v] = true;
        for (int i = 0; i < 26; i++) {
            if (graph[v][i] && !visited[i]) {
                dfs1(i, graph, visited, stack);
            }
        }
        stack.push_back(v);
    }

    void dfs2(int v, vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
        if (batches[v] == -1) {
            batches[v] = batch;
            for (int i = 0; i < 26; i++) {
                if (graph[i][v]) {
                    dfs2(i, graph, batches, batch, degree);
                }
            }
        } else {
            if (batches[v] != batch) {
                degree[batches[v]]++;
            }
        }
    }
};
