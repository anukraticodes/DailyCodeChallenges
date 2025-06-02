class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp;
    for (char t : tasks) mp[t]++;  // Count frequency of each task

    // Max heap of task frequencies
    priority_queue<int> pq;
    for (auto& it : mp) pq.push(it.second);

    int steps = 0;

    while (!pq.empty()) {
        int cycle = 0;
        vector<int> temp;  // Tasks that still need processing

        // Try to schedule up to (n + 1) tasks
        for (int i = 0; i <= n; ++i) {
            if (!pq.empty()) {
                int freq = pq.top(); pq.pop();
                if (freq > 1) temp.push_back(freq - 1);  // Decrement and hold for next round
                cycle++;
            }
        }

        // Push remaining tasks back to heap
        for (int remainingFreq : temp) pq.push(remainingFreq);

        // If heap is empty, no need to pad idle time
        steps += pq.empty() ? cycle : (n + 1);
    }

    return steps;
}

};