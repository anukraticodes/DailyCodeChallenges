class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string base) {
        set<set<char>> st;

        for (int i = 0; i < s1.size(); i++) {
            char a = s1[i], b = s2[i];
            vector<set<char>> toRemove;
            set<char> mergedGroup = {a, b};

            // Merge any groups containing a or b
            for (auto& group : st) {
                if (group.count(a) || group.count(b)) {
                    mergedGroup.insert(group.begin(), group.end());
                    toRemove.push_back(group);
                }
            }

            for (auto& group : toRemove) {
                st.erase(group);
            }

            st.insert(mergedGroup);
        }

        // Convert each group to a map from character -> smallest equivalent
        unordered_map<char, char> mp;
        for (auto& group : st) {
            char smallest = *group.begin();
            for (char ch : group) {
                if (ch < smallest) smallest = ch;
            }
            for (char ch : group) {
                mp[ch] = smallest;
            }
        }

        // Build result
        string res = "";
        for (char ch : base) {
            if (mp.count(ch)) res += mp[ch];
            else res += ch;
        }

        return res;
    }
};
