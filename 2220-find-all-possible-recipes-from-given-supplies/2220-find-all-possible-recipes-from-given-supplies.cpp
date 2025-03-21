class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adj;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size(); 
            for (const string& ing : ingredients[i]) {
                adj[ing].push_back(recipes[i]); 
            }
        }
        for (const string& supply : supplies) {
            q.push(supply);
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();
            if (indegree.count(item)) {
                result.push_back(item);
            }

            for (const string& dependent : adj[item]) {
                if (--indegree[dependent] == 0) {
                    q.push(dependent); 
                }
            }
        }

        return result;
    }
};