class Solution {
public:
    int brokenCalc(int s, int t) {
        int ops = 0;
        while (t > s) {
            if (t % 2 == 0) {
                t /= 2;
            } else {
                t += 1;
            }
            ops++;
        }
        return ops + (s - t);
    }
};
