class Solution {
public:
    bool merge(vector<pair<int, int>>& ranges) {
    if (ranges.empty() || ranges.size() < 3) return false;

    sort(ranges.begin(), ranges.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    vector<pair<int, int>> merged;
    int start = ranges[0].first, end = ranges[0].second;

    for (int i = 1; i < ranges.size(); i++) {
        int a = ranges[i].first, b = ranges[i].second;
        if (a < end) { 
            end = max(end, b);  
        } else {
            merged.emplace_back(start, end);
            start = a, end = b;
        }
    }
    merged.emplace_back(start, end); 

    return merged.size()>=3; 
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    // set<int> x, y;
    vector<pair<int, int>> rangex, rangey;

    for (const auto& rec : rectangles) {
        // x.insert(rec[0]);
        // y.insert(rec[1]);
        // y.insert(rec[3]);
        // x.insert(rec[2]);
        rangex.emplace_back(rec[0], rec[2]);
        rangey.emplace_back(rec[1], rec[3]);
    }
    // if (x.size() < 3 && y.size() < 3) return false;

    return merge(rangex) || merge(rangey);
}
};