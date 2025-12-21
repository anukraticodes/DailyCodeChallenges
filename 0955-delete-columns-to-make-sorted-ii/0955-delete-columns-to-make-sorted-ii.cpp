class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deletions = 0;
        vector<bool> resolved(strs.size() - 1, false);
        isordered(0, resolved, strs, deletions);
        return deletions;
    }

    bool isordered(int col,
               vector<bool>& resolved,
               vector<string>& strs,
               int& deletions)
{
    int n = strs.size();
    if (col == strs[0].size())
        return true;

    // check if this column must be deleted
    for (int i = 0; i < n - 1; i++) {
        if (!resolved[i] && strs[i][col] > strs[i+1][col]) {
            deletions++;
            return isordered(col + 1, resolved, strs, deletions);
        }
    }

    // mark newly resolved pairs
    vector<bool> newResolved = resolved;
    for (int i = 0; i < n - 1; i++) {
        if (!resolved[i] && strs[i][col] < strs[i+1][col]) {
            newResolved[i] = true;
        }
    }

    return isordered(col + 1, newResolved, strs, deletions);
}



};