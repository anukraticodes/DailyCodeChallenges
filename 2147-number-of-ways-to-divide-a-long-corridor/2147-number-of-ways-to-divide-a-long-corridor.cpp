class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1000000007;

        vector<int> seats;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }

        int total = seats.size();
        if (total == 0 || total % 2 != 0) return 0;

        long long ans = 1;

        for (int i = 2; i < total; i += 2) {
            int plants = seats[i] - seats[i - 1] - 1;
            ans = (ans * (plants + 1)) % MOD;
        }

        return ans;
    }
};