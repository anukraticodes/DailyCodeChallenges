class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (const string& word : words) {
            freqMap[word]++;
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first; 
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (const auto& [word, freq] : freqMap) {
            pq.push({freq, word});
            if (pq.size() > k) pq.pop(); 
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
