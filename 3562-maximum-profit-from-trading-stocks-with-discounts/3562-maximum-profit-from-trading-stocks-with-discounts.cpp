class Solution {
public:
    tuple<vector<int>, vector<int>, int> dfs(int u,const vector<vector<int>>& g,
        const vector<int>& present,
        const vector<int>& future,
        int budget){int cost = present[u];
        int dCost = present[u] / 2;

        vector<int> dp0(budget + 1, 0);
        vector<int> dp1(budget + 1, 0);

        vector<int> subProfit0(budget + 1, 0);
        vector<int> subProfit1(budget + 1, 0);

        int uSize = cost;

        for (int v : g[u]) {
            auto [subDp0, subDp1, vSize] =
                dfs(v, g, present, future, budget);

            uSize += vSize;

            for (int i = budget; i >= 0; i--) {
                for (int sub = 0; sub <= min(vSize, i); sub++) {
                    subProfit0[i] = max(subProfit0[i],
                                        subProfit0[i - sub] + subDp0[sub]);
                    subProfit1[i] = max(subProfit1[i],
                                        subProfit1[i - sub] + subDp1[sub]);
                }
            }
        }

        for (int i = 0; i <= budget; i++) {
            dp0[i] = dp1[i] = subProfit0[i];

            // parent bought → discount available
            if (i >= dCost) {
                dp1[i] = max(dp1[i],
                             subProfit1[i - dCost] + future[u] - dCost);
            }

            // parent not bought → no discount
            if (i >= cost) {
                dp0[i] = max(dp0[i],
                             subProfit1[i - cost] + future[u] - cost);
            }
        }

        return {dp0, dp1, uSize};
    }

    int maxProfit(int n,
                  vector<int>& present,
                  vector<int>& future,
                  vector<vector<int>>& hierarchy,
                  int budget) {

        vector<vector<int>> g(n);
        for (auto& e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }

        auto [dp0, dp1, _] = dfs(0, g, present, future, budget);
        return dp0[budget];
    }
};