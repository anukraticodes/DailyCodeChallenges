class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> radiant, dire;
        int n = s.size();

       
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

       
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            if (r < d) {
               
                radiant.push(r + n);
            } else {
               
                dire.push(d + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
