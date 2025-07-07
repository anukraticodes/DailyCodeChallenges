class Solution {
public:
    vector<int> parent;

    int find(int day) {
        if (parent[day] != day)
            parent[day] = find(parent[day]); 
        return parent[day];
    }

    void unite(int u, int v) { parent[u] = v; }

    int maxEvents(vector<vector<int>>& events) {
        int cnt = 0;
        sort(events.begin(), events.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int n = events[events.size() - 1][1];
        parent.resize(n + 2);
        for (int i = 0; i <= n + 1; i++)
            parent[i] = i;
        for (auto it : events) {
            int u = it[0], v = it[1];
            int avail = find(u);
            if (avail <= v) {
                unite(avail, avail + 1);
                cnt++;
            }
        }

        return cnt;
    }
};