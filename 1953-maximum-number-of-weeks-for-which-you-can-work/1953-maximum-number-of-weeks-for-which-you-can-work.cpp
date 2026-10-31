class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long mx = 0;

        for (int x : milestones) {
            sum += x;
            mx = max(mx, (long long)x);
        }

        long long rem = sum - mx;

        if (mx <= rem + 1) {
            return sum;
        }

        return 2 * rem + 1;
    }
};