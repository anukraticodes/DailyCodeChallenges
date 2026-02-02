class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        if (n % gs != 0) return false;

        unordered_map<int, int> freq;
        for (int x : hand) freq[x]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &p : freq)
            pq.push(p.first);

        while (!pq.empty()) {
            int start = pq.top();

            // try to build one group of size gs
            for (int i = 0; i < gs; i++) {
                int card = start + i;

                if (freq[card] == 0)
                    return false;

                freq[card]--;

                // if frequency becomes zero, it MUST be the heap top
                if (freq[card] == 0) {
                    if (pq.empty() || pq.top() != card)
                        return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};
