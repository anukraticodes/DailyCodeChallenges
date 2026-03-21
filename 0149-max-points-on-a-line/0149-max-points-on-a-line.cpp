class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2)
            return points.size();
        int ans = 2;
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> mp;
            for (int j = i + 1; j < points.size(); j++) {
                int dy = (points[j][1] - points[i][1]);
                int dx = (points[j][0] - points[i][0]);
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx == 0)
                    dy = 1;
                else if (dy == 0)
                    dx = 1;
                else if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
                pair<int, int> curr = {dx, dy};
                mp[curr]++;
            }
            for (auto it : mp) {
                ans = max(ans, it.second + 1);
            }
        }
        return ans;
    }
};